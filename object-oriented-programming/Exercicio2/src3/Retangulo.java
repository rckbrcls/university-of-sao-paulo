/**
 * Classe Retangulo filha de FigurasGeometricas
 * @author Erick Barcelos (11345562)
 *
 */
public class Retangulo extends FigurasGeometricas {
	private double base; // Variavel auxiliar base 
	/**
	 * Construtor da classe retangulo
	 * @param b
	 * @param h
	 * @param c
	 * @param f
	 */
	public Retangulo(double b, double h, String c, boolean f) {
		super(h, c, f);
		base = b; 
	}
	/**
	 * Calcula perimetro do retangulo
	 * @return
	 */
	public double perimetro() {
		return ((2 * base) + (2 * medida));
	}
	/**
	 * Calcula a area do retangulo
	 * @return
	 */
	public double area() {
		return (base * medida);
	}
	
}
