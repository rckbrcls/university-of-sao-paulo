/**
 * Classe filha Livro da classe Produto
 * @author Erick Barcelos(11345562)
 *
 */
public class Livro extends Produto {
	private int paginas; // Numero de paginas
	/**
	 * Construtor da classe Livro
	 * @param n
	 * @param cat
	 * @param cod
	 * @param pag
	 */
	public Livro(String n, String cat, String cod, int pag) {
		super(n, cat, cod);
		paginas = pag;
	}
	/**
	 * Retorna o numero de paginas
	 * @return
	 */
	public int getPaginas() {
		return paginas;
	}
	/**
	 * Atribui um numero de paginas
	 * @param x
	 */
	public void setPaginas(int x) {
		this.paginas = x;
	}
	
}
