/**
 * Classe filha DVD da classe Produto
 * @author Erick Barcelos(11345562)
 *
 */
public class DVD extends Produto{
	private double duracao;// Duracao do DVD
	/**
	 * Construtor da classe DVD
	 * @param n
	 * @param cat
	 * @param cod
	 * @param d
	 */
	public DVD(String n, String cat, String cod, double d) {
		super(n, cat, cod);
		duracao = d;
	}
	/**
	 * Retorna a duracao do DVD
	 * @return
	 */
	public double getDuracao() {
		return duracao;
	}
	/**
	 * Atribui uma duracao para o DVD
	 * @param x
	 */
	public void setDuracao(double x) {
		this.duracao = x;
	}
}
