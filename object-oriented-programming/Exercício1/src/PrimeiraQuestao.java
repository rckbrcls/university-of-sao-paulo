// Erick Barcelos | NUSP: 11345562


public class PrimeiraQuestao {

	public static void main(String[] args) {
		
		System.out.println("Digite o X: ");
		//Função de leitura tratando exceções feita na classe da questão dois
		double x = SegundaQuestao.lerValores(); 
		
		double raiz = acharRaiz(x); 
		
		System.out.println("A raiz quadrada é " + raiz);
		
	}
	
	// Função para achar raiz
	public static double acharRaiz(double x) {
		
		System.out.println("Digite o seu chute inicial");
		
		double atual = SegundaQuestao.lerValores();
		double antes;
		
		// Lógica para achar raiz quadrada
		do{
			antes = atual;
			atual = (antes + (x / antes)) / 2;
		}while ((atual - antes) >= 0.00000001); // Enquanto a diferença não for maior que o erro
		
		return atual; // Retorna a raiz
	}
}
