/**
 * Classe Quadrado filha de FigurasGeometricas
 * @author Erick Barcelos (11345562)
 *
 */
public class Quadrado extends FigurasGeometricas {
	/**
	 * Construtor da classe quadrado
	 * @param x
	 * @param c
	 * @param f
	 */
	public Quadrado(double x, String c, boolean f) {
		super(x, c, f);
	}
	/**
	 * Calcula o perimetro do quadrado
	 * @return
	 */
	public double perimetro() {
		return (4 * medida);
	}
	/**
	 * Calcula a area do quadrado
	 * @return
	 */
	public double area() {
		return (medida * medida);
	}
	
}
