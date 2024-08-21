//package view;

public class Pergunta {
	public String pergunta;
	public String[] alternativa = {"","","",""};
	public String dificuldade;
	
	public Pergunta() {

	}
	
	public static void main(String[] args) {
	
	}

	public String getPergunta() {
		return this.pergunta;
	}
	
	public void setPergunta(String pergunta) {
		this.pergunta = pergunta;
	}
	
	
	public String[] getAlternativa() {
		return this.alternativa;
	}
	
	public void setAlternativa(String alternativa[]) {
		this.alternativa = alternativa;
	}
	
	public String getDificuldade() {
		return this.dificuldade;
	}
	
	public void setDificuldade(String dificuldade) {
		this.dificuldade = dificuldade;
	}
	
}
