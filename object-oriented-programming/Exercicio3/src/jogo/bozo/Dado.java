package jogo.bozo;
/**
 * Simula um dado de número de lados variados. 
 * Ao criar o objeto é possível estabelecer o número de lados. 
 * A rolagem do dado é feita por meio de um gerador de números aleatórios (Random).
 * @author Erick Barcelos (11345562)
 *
 */

public class Dado {
	
	private int numeroLados;
	public int ladoSuperior;
	private Random rand = new Random();

	//Constructors
	/**
	 * Cria um dado com 6 lados (um cubo)
	 */
	public Dado(){
		numeroLados = 6;
		rolar();
	}
	/**
	 * Cria objeto com um número qualquer de lados
	 * @param n - - número de lados do dado
	 */
	public Dado(int n) {
		numeroLados = n;
		rolar();
	}
	//Methods
	/**
	 * Não tem função real dentro da classe. 
	 * Foi usada apenas para testar os métodos implementados
	 * @param args - -- Sem uso
	 
	public static void main(String[] args) {
		Dado d = new Dado();
		d.rolar();
		System.out.println("Lado: \n" +d);
	}
	
	*/
	/**
	 * Recupera o último número selecionado.
	 * @return o número do último lado selecionado.
	 */
	public int getLado() {
		return ladoSuperior;
	}
	/**
	 * Simula a rolagem do dado por meio de um gerador aleatório. 
	 * O número selecionado pode posteriormente ser recuperado com a chamada a getLado()
	 * @return o número que foi sorteado
	 */
	public int rolar() {
		ladoSuperior =  1 + rand.getIntRand(numeroLados);
		return ladoSuperior;
	}
	/**
	 * Transforma representação do dado em String. 
	 * É mostrada uma representação do dado que está para cima. 
	 * Note que só funciona corretamente para dados de 6 lados. Exemplo:
	 * +-----+    
	 * |*   *|    
	 * |  *  |    
	 * |*   *|    
	 * +-----+
	 * @override toString in class java.lang.Object
	 */
	@Override
	public String toString() {
			switch(getLado()){
			case 1: return "+-----+\n|     |\n|  *  |\n|     |\n+-----+\n";
			case 2: return "+-----+\n|    *|\n|     |\n|*    |\n+-----+\n";
			case 3: return "+-----+\n|    *|\n|  *  |\n|*    |\n+-----+\n";
			case 4: return "+-----+\n|*   *|\n|     |\n|*   *|\n+-----+\n";
			case 5: return "+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+\n";
			case 6: return "+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+\n";
			}
			return "";
	}
	
}