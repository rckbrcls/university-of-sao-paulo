/**
 * Classe Circulo filha de FigurasGeometricas
 * @author Erick Barcelos (11345562)
 *
 */
public class Circulo extends FigurasGeometricas{
	private double pi = 3.14159265359;// Variavel auxiliar pi para o calculo
	/**
	 * Construtor da classe circulo
	 * @param x
	 * @param c
	 * @param f
	 */
	public Circulo(double x, String c, boolean f) {
		super(x, c, f);
	}
	/**
	 * Calcula perimetro do circulo
	 * @return
	 */
	public double perimetro() {
		return (2 * pi * medida);
	}
	/**
	 * Calcula a area do circulo
	 * @return
	 */
	public double area() {
		return (pi * (medida * medida));
	}
}
