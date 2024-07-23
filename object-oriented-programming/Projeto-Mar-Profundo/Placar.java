
public class Placar {
	private int placar;
	private String userName;
	
	Placar(int placar, String userName){
		this.placar = placar;
		this.userName = userName;
	}
	
	Placar(String userName){
		this.placar = 0;
		this.userName = userName;
	}
	
	public int getPlacar() {
		return placar;
	}
	
	public String getUserName() {
		return userName;
	}
	
	public void setPlacar(int newPlacar) {
		placar = newPlacar;
	}
	
	public void addToPlacar(int addPoints) {
		placar += addPoints;
	}
	
	@Override
	public String toString() {
		return userName + " - " + placar + '\n';
	}
}
