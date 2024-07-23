/**
 * Classe pai de figuras geometricas 
 * @author Erick Barcelos (11345562)
 *
 */
public class FigurasGeometricas {
	protected double medida; // medida que pode ser o raio ou um lado 
	protected String cor;
	protected boolean filled;
	/**
	 * Construtor da classe
	 * @param x
	 * @param c
	 * @param f
	 */
	public FigurasGeometricas(double x, String c, boolean f) {
		medida = x;
		cor = c;
		filled = f;
	}
	/**
	 * Retorna a medida
	 * @return
	 */
	public double getMedida() {
		return medida;
	}
	/**
	 * Atribui uma medida
	 * @param x
	 */
	public void setMedida(double x) {
		this.medida = x;
	}
	/**
	 * Retorna o filled
	 * @return
	 */
	public boolean getFilled() {
		return filled;
	}
	/**
	 * Atribui um filled
	 * @param f
	 */
	public void setFilled(boolean f) {
		this.filled = f;
	}
	/**
	 * Retorna a cor, caso o filled seja verdadeiro,
	 * se nao, retorna uma string dizendo que nao possui cor
	 * e atribui null para a variavel cor
	 * @return
	 */
	public String getCor() {
		if(getFilled())
			return cor;
		
		cor = null;
		return "Nao tem cor";
	}
	/**
	 * Atribui uma cor, so se o filled for verdadeiro, 
	 * se nao, atribui null 
	 * @param c
	 */
	public void setCor(String c) {
		if(getFilled())
			this.cor = c;
		this.cor = null;	
	}
	
	
	
}
