import java.io.IOException;
/**
 * Classe que representa as figuras geometricas
 * @author Erick Barcelos (11345562)
 *
 */
public class CriarFigurasGeometricas {
	/**
	 * Metodo principal que seleciona qual figura se deseja representar,
	 * devolvendo seu perimetro, sua area e sua cor, caso tenha
	 * @param args
	 * @throws NumberFormatException
	 * @throws IOException
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		int op = 0;
		double x = 0, x1 = 0;
		String cor = new String();
		int escolhaFilled = 0;
		boolean filled;
		
		CriarFigurasGeometricas fig = new CriarFigurasGeometricas();
		
		while (op != 4) {
			op = fig.leOpcao();
			switch (op){
				case 1:
					System.out.println("Entre com o raio do circulo: \n");
					x = EntradaTeclado.leDouble();
					
					System.out.println("Entre com a cor: \n");
					cor = EntradaTeclado.leString();
					
					System.out.println("Entre com o filled (1 => SIM | 0 => NAO): \n");
					escolhaFilled = EntradaTeclado.leInt();
					
					if(escolhaFilled == 1) // verifica se ele quer preencher ou nao
						filled = true;
					else
						filled = false;
					
					Circulo c = new Circulo(x, cor, filled);
					
					System.out.println("Perimetro: " + c.perimetro());
					System.out.println("Area: " + c.area());
					System.out.println("Cor: " + c.getCor());
					
					break;
				case 2:
					System.out.println("Entre com a base do retangulo:");
					x = EntradaTeclado.leDouble();
					
					System.out.println("Entre com a altura do retangulo:");
					x1 = EntradaTeclado.leDouble();
					
					System.out.println("Entre com a cor: ");
					cor = EntradaTeclado.leString();
					
					System.out.println("Entre com o filled (1 => SIM | 0 => NAO): \n");
					escolhaFilled = EntradaTeclado.leInt();
					
					if(escolhaFilled == 1)
						filled = true;
					else
						filled = false;
					
					Retangulo r = new Retangulo(x, x1, cor, filled);
					
					System.out.println("Perimetro: " + r.perimetro());
					System.out.println("Area: " + r.area());
					System.out.println("Cor: " + r.getCor());
					
					break;
				case 3:
					System.out.println("Entre com o lado do quadrado");
					x = EntradaTeclado.leDouble();
					
					System.out.println("Entre com a cor: ");
					cor = EntradaTeclado.leString();
					
					System.out.println("Entre com o filled (1 => SIM | 0 => NAO): \n");
					escolhaFilled = EntradaTeclado.leInt();
					
					if(escolhaFilled == 1)
						filled = true;
					else
						filled = false;
					
					Quadrado q = new Quadrado(x, cor, filled);
					
					System.out.println("Perimetro: " + q.perimetro());
					System.out.println("Area: " + q.area());
					System.out.println("Cor: " + q.getCor());
					
					break;
				
			}
		}
	}	
	/**
	 * Le a opcao que o usuario selecionou
	 * @return
	 */
	private int leOpcao() {
        System.out.println("1) Representar circulo\n2) Representar retangulo\n3) Representar quadrado\n4) Sair\n");
        int k = -1;
        
        while (true)
        {
        	System.out.println("Digite a opcao desejada ===> ");
        	try {
        		k = EntradaTeclado.leInt();
        		if ( k > 0 && k < 5 )
        			return k;
        	}
        	catch (Exception e) {
        		;
        	}
        }
	}
}
