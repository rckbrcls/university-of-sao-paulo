/**
 * Classe pai dos produtos da loja
 * @author Erick Barcelos(11345562)
 *
 */
public class Produto {
	private String nome;
	private String categoria;
	private String codigoDeBarras;
	/**
	 * Construtor da classe Produto
	 * @param n
	 * @param cat
	 * @param cod
	 */
	public Produto(String n, String cat, String cod) {
		nome = n;
		categoria = cat;
		codigoDeBarras = cod;
	}
	/**
	 * Retorna a categoria do produto
	 * @return
	 */
	public String getCategoria() {
		return categoria;
	}
	/**
	 * Atribui uma categoria para produto
	 * @param n
	 */
	public void setCategoria(String n) {
		this.categoria = n;
	}
	/**
	 * Retorna o codigo de barras do produto
	 * @return
	 */
	public String getCodDeBarras() {
		return codigoDeBarras;
	}
	/**
	 * Atribui um codigo de barras para o produto
	 * @param n
	 */
	public void setCodDeBarras(String n) {
		this.codigoDeBarras = n;
	}
	/**
	 * Retorna o nome do produto
	 * @return
	 */
	public String getNome() {
		return nome;
	}
	/**
	 * Atribui um nome para o produto
	 * @param n
	 */
	public void setNome(String n) {
		this.nome = n;
	}
	
}
