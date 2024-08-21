
public class Ranking {

	private Placar listaPlacar[];
	private int tamanhoRanking;
	
	Ranking() {
		listaPlacar = new Placar[100];
		
		String placarAsString[] = Arquivos.readFile("ranking.txt");
		
		int i;
		
		for(i=0;i<100;i++) {
			if(placarAsString[i] != null) {
				String[] splitedPlacar = placarAsString[i].split(",");
				listaPlacar[i] = new Placar(Integer.parseInt(splitedPlacar[1]), splitedPlacar[0]); 				
			} else {
				break;
			}
		}
		
		tamanhoRanking = i;
	}
	
	public int getTamanhoRanking() {
		return tamanhoRanking;
	}
	
	public void addToRanking(Placar newPlacar) {
		int indexPivo = tamanhoRanking;
			
		for(int i=0;i<tamanhoRanking;i++) {
			if(listaPlacar[i].getPlacar() < newPlacar.getPlacar()) {
				indexPivo = i;
				break;
			}
		}
		
		
		for(int i=tamanhoRanking;i>indexPivo;i--) {
			listaPlacar[i] = listaPlacar[i-1];
		}
				
		listaPlacar[indexPivo] = newPlacar;
		
		tamanhoRanking++;
		
	}
	
	public Placar getPlacarByIndex(int index) {
		return listaPlacar[index];
	}
	
	public Placar getPlacarByUserName(String userName) {
		for (int i=0;i<tamanhoRanking;i++) {
			if(listaPlacar[i].getUserName().equals(userName)) {
				return listaPlacar[i];
			}
		}
		
		return null;
	}
	
	public void updateRankingFile() {
		String placarString[] = new String[100];
		
		for(int i=0;i<tamanhoRanking;i++) {
			placarString[i] = listaPlacar[i].getUserName() + "," + listaPlacar[i].getPlacar() + "\n"; 				
		}
		
		Arquivos.writeFile("ranking.txt", placarString);
	}
	
	
	@Override
	public String toString() {
		String rankingToString = "";
		
		for(int i=0;i<100;i++) {
			if(listaPlacar[i] != null) {
				rankingToString += listaPlacar[i].toString();
			}
		}
		
		return rankingToString;
	}
	
}
