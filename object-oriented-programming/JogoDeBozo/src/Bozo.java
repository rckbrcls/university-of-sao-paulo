import java.io.IOException;

/**
 * Essa é a classe inicial do programa Bozó. 
 * Possui apenas o método main, que cuida da execução do jogo.
 * @author Erick Barcelos (11345562)
 *
 */

public class Bozo {
	/**
	 * Método inicial do programa. 
	 * Ele cuida da execução do jogo e possui um laço, no qual cada iteração representa uma rodada do jogo. 
	 * Em cada rodada, o jogador joga os dados até 3 vezes e depois escolhe a posição do placar que deseja preencher. 
	 * No final das rodadas a pontuação total é exibida.
	 * @param args -
	 * @throws java.io.IOException -
	 */
	public static void main(String[] args) throws IOException {
		Placar placar = new Placar();
		RolaDados dados= new RolaDados(5);
		String ler = new String();
		
		int[] valores = new int[5];
		int posicao;
		
		System.out.print("Jogo de Bozó!" + placar);
		
		for(int i = 0; i < 10; i++) {
			System.out.print("****** Rodada " + (i+1));
			System.out.print("\nPressione ENTER para lançar os dados");
			
			EntradaTeclado.leString();
			
			dados.rolar();

			System.out.println(dados);			
			System.out.println("Digite os números dos dados que quiser TROCAR. Separados por espaços.");		
			
			ler = EntradaTeclado.leString();
			dados.rolar(ler);
			
			System.out.println(dados);
			System.out.println("Digite os números dos dados que quiser TROCAR. Separados por espaços.");
			
			ler = EntradaTeclado.leString();
			valores = dados.rolar(ler);
		
			System.out.println(dados);
			System.out.print(placar);
			System.out.println("Escolha a posição que quer ocupar com essa jogada ====> ");
			
			for(;;) {
				try {
					posicao = EntradaTeclado.leInt();
					placar.add(posicao, valores);	
					break;
				} catch (IllegalArgumentException e) { 
					System.out.println("Posição ocupada ou valor inválido. Digite novamente ====> ");
				}
			}
			System.out.print(placar);
		}
		System.out.print("\n******************************************\n");
		System.out.print("Seu escore final foi: " + placar.getScore());
		System.out.print("\n******************************************");
	}

}
