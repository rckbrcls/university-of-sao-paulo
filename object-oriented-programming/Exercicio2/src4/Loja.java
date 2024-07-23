import java.io.IOException;
import java.util.Arrays;
/**
 * Classe principal, que vai gerenciar o estoque da loja,
 * fazendo insercao, remocao, procura e impressao dos produtos
 * da loja
 * @author Erick Barcelos(11345562)
 *
 */
public class Loja {
	private int MAX = 100;// Maximo de produtos
	private Produto estoque[] = new Produto[MAX];
	private int nProdutos = 0; 
	/**
	 * Metodo principal que faz a selecao das acoes que podem ser
	 * feitas no estoque da loja
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		Loja l = new Loja(); 
		
		//Variaveis auxiliares
		int op = 0;
		int inteiro = 0;
		double flutuante = 0;
		String s1 = new String();
		String s2= new String();
		String s3 = new String();
		
		// Opcoes
		while (op != 7) {
			op = l.leOpcao();
			switch (op){
				case 1:// Insere um DVD
					System.out.println("Entre com o nome do DVD: \n");
					s1 = EntradaTeclado.leString();
					
					System.out.println("Entre com a categoria do DVD: \n");
					s2 = EntradaTeclado.leString();
					
					System.out.println("Entre com o codigo de barras do DVD, no tipo EAN-13 (13 digitos): \n");
					
					for(;;){
						s3 = EntradaTeclado.leString();
						
						if(l.verificaCodDeBarras(s3))
							break;
						else
							System.out.println("Codigo de barras invalido, digite de novo com o tipo EAN-13: \n");
					}
					
					System.out.println("Entre com a duracao do DVD: \n");
					flutuante = EntradaTeclado.leDouble();
					
					DVD d = new DVD(s1, s2, s3, flutuante);
					l.addProduto(d);
		
					break;
				case 2: // Insere CD
					System.out.println("Entre com o nome do CD: \n");
					s1 = EntradaTeclado.leString();
					
					System.out.println("Entre com a categoria do CD: \n");
					s2 = EntradaTeclado.leString();
					
					System.out.println("Entre com o codigo de barras do CD, no tipo EAN-13 (13 digitos): \n");
					
					for(;;){
						s3 = EntradaTeclado.leString();
						
						if(l.verificaCodDeBarras(s3))
							break;
						else
							System.out.println("Codigo de barras invalido, digite de novo com o tipo EAN-13: \n");
					}
					
					System.out.println("Entre com o numero de musicas do CD: \n");
					inteiro = EntradaTeclado.leInt();
					
					CD c = new CD(s1, s2, s3, inteiro);
					l.addProduto(c);
				
					break;
				case 3:// Insere livro
					System.out.println("Entre com o nome do livro: \n");
					s1 = EntradaTeclado.leString();
					
					System.out.println("Entre com a categoria do livro: \n");
					s2 = EntradaTeclado.leString();
					
					System.out.println("Entre com o codigo de barras do livro, no tipo EAN-13 (13 digitos): \n");
					
					for(;;){
						s3 = EntradaTeclado.leString();
						
						if(l.verificaCodDeBarras(s3))
							break;
						else
							System.out.println("Codigo de barras invalido, digite de novo com o tipo EAN-13: \n");
					}
					
					System.out.println("Entre com a duracao do livro: \n");
					inteiro = EntradaTeclado.leInt();
					
					Livro liv = new Livro(s1, s2, s3, inteiro);
					l.addProduto(liv);
					
					break;
				case 4: // Vende produto
					System.out.println("Entre com o codigo de barras ou nome do produto que voce deseja vender: \n");
					s1 = EntradaTeclado.leString();
					l.venderProduto(s1);
					break;
				case 5: // Procura produto
					System.out.println("Entre com o codigo de barras ou nome do produto que voce deseja procurar: \n");
					s1 = EntradaTeclado.leString();
					Produto p = l.busca(s1);
					
					if(p != null) {
						System.out.println("O produto procurado: \n");
						l.imprimirProduto(p);
					}
					
					break;
				case 6: // Mostra todo o estoque
					System.out.println("Todo o estoque: \n");
					l.imprimirEstoque();
					break;
			}
		}
		
	}
	/**
	 * Le a opcao que o usuario selecionou
	 * @return
	 */
	private int leOpcao() {
        System.out.println("1) Adicionar DVD\n2) Adicionar CD\n3) Adicionar livro\n4) Remover produto\n"
        		+ "5) Procurar produto\n6) Imprimir estoque\n7) Sair");
        int k = -1;
        
        while (true)
        {
        	System.out.println("Digite a opcao desejada ===> ");
        	try {
        		k = EntradaTeclado.leInt();
        		if ( k > 0 && k < 8 )
        			return k;
        	}
        	catch (Exception e) {
        		;
        	}
        }
	}
	/**
	 * Imprime somente um produto, antes verificando qual eh a classe que ele pertence
	 * @param p
	 */
	public void imprimirProduto(Produto p) {
		System.out.println("-----------------------------");
		if ( p instanceof DVD ){
			DVD e = (DVD) p;
			System.out.println("\nNome do DVD: " + e.getNome());
			System.out.println("\nCategoria do DVD: " + e.getCategoria());
			System.out.println("\nCodigo de barras do DVD: " + e.getCodDeBarras());
			System.out.println("\nDuracao do DVD: " + e.getDuracao());
		}else if ( p instanceof CD ) {
			CD e = (CD) p;
			System.out.println("\nNome do CD: " + e.getNome());
			System.out.println("\nCategoria do CD: " + e.getCategoria());
			System.out.println("\nCodigo de barras do CD: " + e.getCodDeBarras());
			System.out.println("\nNumero de musicas do CD: " + e.getNumMusicas());
		}else if ( p instanceof Livro ) {
			Livro e = (Livro) p;
			System.out.println("\nNome do livro: " + e.getNome());
			System.out.println("\nCategoria do livro: " + e.getCategoria());
			System.out.println("\nCodigo de barras do livro: " + e.getCodDeBarras());
			System.out.println("\nNumero de paginas do livro: " + e.getPaginas());
		}
		System.out.println("-----------------------------");
	}
	/**
	 * Imprime todo o estoque, verifica
	 * se a primeira posicao do vetor estoque eh vazia,
	 * se for, o estoque esta vazio
	 */
	public void imprimirEstoque() {
		if (estoque[0] == null ) {
			System.out.println("Estoque vazio!");
			return;
		}
		
		for (Produto aux: estoque) {
			if ( aux == null ) break;
			imprimirProduto(aux);
		}
	}
	/**
	 * Verifica se o codigo de barras eh valido usando regex
	 * @param s
	 * @return
	 */
	public boolean verificaCodDeBarras(String s) {
		return s.matches("[0-9]{13}");
	}
	/**
	 * Funcao que adiciona um produto para o estoque,
	 * caso o numero de produtos seja o mesmo do maximo
	 * permitido, retorna que o estoque esta cheio
	 * @param p
	 */
	public void addProduto (Produto p) {
		if (nProdutos == MAX) {
			System.out.println("Estoque cheio!");
			return;
		}
		
		estoque[nProdutos++] = p;
	}
	/**
	 * Vende o produto a partir de uma string, que pode
	 * ser um codigo de barras ou um nome. Primeiro busca o index de onde a string
	 * esta no vetor, depois verifica se esta no final ou no incio/meio 
	 * do vetor, em seguida remove do vetor
	 * @param s
	 */
	public void venderProduto(String s) {
		int pos = buscarIndexProduto(s);
		
		if (pos == -1)
			return; 
        
		if(nProdutos == MAX)
			estoque = Arrays.copyOf(estoque, estoque.length-1);
		else
	        for (int i = pos; i < nProdutos; i++)
	            estoque[i] = estoque[i + 1];
		
		nProdutos--;
		
		System.out.println("Produto vendido com sucesso!");
	}
	/**
	 * Faz a busca de um produto usando seu codigo
	 * de barra ou nome, e retorna uma classe Produto
	 * @param s
	 * @return
	 */
	public Produto busca(String s) {
		int indice = buscarIndexProduto(s);
		
		if(indice > -1) 
			return estoque[indice];
		
		return null;
	}
	/**
	 * Busca o index de uma certa string no
	 * vetor contatos
	 * @param s
	 * @return
	 */
	public int buscarIndexProduto(String s) {
		int i = 0;
		
		if(verificaCodDeBarras(s)) { // verifica se a string eh um codigo de barras
			
			for (Produto aux: estoque) {
				if ( aux == null ) break;
				
				if(aux.getCodDeBarras().compareTo(s) == 0) // compara
					return i;
				
				i++;
			}
		} else { // se nao, pode ser um nome, entao procura
			for (Produto aux: estoque) {
				if ( aux == null ) break;

				if (aux.getNome().compareTo(s) == 0) //compara
					return i;
				i++;
			}
		}
		// se nao achar, retorna -1
		System.out.println("Elemento não achado");
		
		return -1;
	}

}
