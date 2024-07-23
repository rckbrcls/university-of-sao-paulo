/**
 * Classe filha CD da classe Produto
 * @author Erick Barcelos(11345562)
 *
 */
public class CD extends Produto{
	private int nMusicas; // Numero de musicas do cd
	/**
	 * Construtor da classe CD
	 * @param n
	 * @param cat
	 * @param cod
	 * @param num
	 */
	public CD(String n, String cat, String cod, int num) {
		super(n, cat, cod);
		nMusicas = num;
	}
	/**
	 * Retorna o numero de musicas do ce
	 * @return
	 */
	public int getNumMusicas() {
		return nMusicas;
	}
	/**
	 * Atribui um numero de musicas no CD
	 * @param x
	 */
	public void setNumMusicas(int x) {
		this.nMusicas = x;
	}
	
}
