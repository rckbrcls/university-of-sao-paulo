/**
 *Essa é uma classe auxiliar que permite gerencia um conjunto de vários dados simultaneamente. 
 *Operações como rolar alguns dos dados ou exibir o resultado de todos eles, são implementadas. 
 * @author Erick Barcelos (11345562)
 *
 */

public class RolaDados {
	
	private Dado[] dados;
	private int numeroDados;
	private int[] valoresDados;
	
	//Constructors
	/**
	 * Construtor que cria e armazena vários objetos do tipo Dado. 
	 * Usa para isso o construtor padrão daquela classe, ou seja, um dado de 6 lados e gerando sempre uma semente aleatória para o gerador de números aleatórios. 
	 * Os dados criados podem ser referenciados por números, entre 1 e n.
	 * @param n - Número de dados a serem criados.
	 */
	public RolaDados(int n) {
		
		numeroDados = n;
		dados = new Dado[n];
		
		for (int i = 0; i < numeroDados; ++i)
			dados[i] = new Dado();
		
		valoresDados = new int [numeroDados];
	}
	//Methods
	/**
	 * @throws java.lang.Exception
	 */
	public static void main(String[] args) throws Exception{
	}
	
	/**
	 * Rola todos os dados.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados. 
	 * Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	 */
	public int[] rolar() {
		
		for(int i = 0; i < numeroDados; i++) 
			valoresDados[i] = dados[i].rolar();
		
		return valoresDados;
	}
	/**
	 * Rola alguns dos dados.
	 * @param quais - É um array de booleanos que indica quais dados devem ser rolados. 
	 * Cada posição representa um dos dados. 
	 * Ou seja, a posição 0 do array indica se o dado 1 deve ser rolado ou não, e assim por diante.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados. 
	 * Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	 */
	public int[] rolar(boolean[] quais) {
		
		for (int i = 0; i < numeroDados; i++)
			if (quais[i])
				valoresDados[i] = dados[i].rolar();
		
		return valoresDados;
	}
	/**
	 * Rola alguns dos dados.
	 * @param s - É um String que possui o número dos dados a serem rolados. 
	 * Por exemplo "1 4 5" indica que os dados 1 4 e cinco devem ser rolados. 
	 * Os números devem ser separados por espaços. 
	 * Se o valor passado no string estiver fora do intervalo válido, ele é ignorado simplesmente.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados. Nesse caso, o valor retornado é o valor anterior que ele já possuia.
	 */
	public int[] rolar(String s) {
		
		if(!s.isEmpty()) {
			String[] auxiliar = s.split(" ");
			
			for (int i = 0; i < auxiliar.length; i++) {
				int posicao = Integer.parseInt(auxiliar[i]);
				
				if (posicao > 0 && posicao <= numeroDados)
					dados[posicao-1].rolar();
			}
		}
		
		for (int i = 0; i < numeroDados; i++)
			valoresDados[i] = dados[i].getLado();
		
		return valoresDados;
	}
	
	/**
	 * Usa a representação em string do dados, para mostrar o valor de todos os dados do conjunto. 
	 * Exibe os dados horisontalmente, por exemplo:
	 * @override toString in class java.lang.Object
	 */
	@Override
	public String toString() {
		String auxiliar = new String();
		String[][] vetorString = new String[numeroDados][];
		
		for (int i = 0; i < numeroDados; ++i)
			vetorString[i] = dados[i].toString().split("\\n");
		
		for (int i = 0; i < numeroDados; ++i) 
			auxiliar += (i + 1) + "       ";
		
		auxiliar += '\n';

		for (int i = 0; i < vetorString.length; ++i) {
			for (int j = 0; j < numeroDados; ++j)
				auxiliar += vetorString[j][i] + ' ';
			auxiliar += '\n';
		}
		
		auxiliar += '\n';
		
		return auxiliar;
	}
}
