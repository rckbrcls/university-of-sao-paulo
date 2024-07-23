import java.util.Random;
import java.util.regex.Pattern;

//package view;

public class DeckDePerguntas {
	public Pergunta[] arrayPerguntas;
	public int nroPerguntas;
	public int limitePerguntas;
	public String categoria;
	public Random rand;
	public int faceis[] = {-1,-1,-1,-1,-1};
	public int medias[] = {-1,-1,-1,-1,-1};
	public int dificeis[] = {-1,-1,-1,-1,-1};
	
	public DeckDePerguntas(int n) {
		this.arrayPerguntas = new Pergunta[n]; //Isso não inicializa as perguntas		
		this.nroPerguntas = 0;
		this.limitePerguntas = n;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	public void lerPerguntas(String categoria)
	{
		String linhas[] = Arquivos.lerPerguntas(categoria);

		this.categoria = categoria;
		
		//System.out.print();
		
		for(int i = 0; i < limitePerguntas; i++)
		{
			this.arrayPerguntas[i] = new Pergunta();
			String pergAlt[] = linhas[i+1].split(Pattern.quote(",")); //pegar as perguntas e alternativas
			//this.arrayPerguntas[i].pergunta = pergAlt[0]; //Perguntas
			this.arrayPerguntas[i].setPergunta(pergAlt[0]); //Pergunta
			this.arrayPerguntas[i].alternativa[0] = pergAlt[1]; //Alternativa A
			this.arrayPerguntas[i].alternativa[1] = pergAlt[2]; //Alternativa B
			this.arrayPerguntas[i].alternativa[2] = pergAlt[3]; //Alternativa C
			this.arrayPerguntas[i].alternativa[3] = pergAlt[4]; //Alternativa D
			this.arrayPerguntas[i].dificuldade = pergAlt[5]; //Dificuldade
			//System.out.print(pergAlt[5] == "F");
			if(pergAlt[5].intern() == "F")
			{
				
				for(int j = 0; j < 5; j++)
					if(this.faceis[j] == -1)
					{
						this.faceis[j] = i;
						
						break;
					}
			} else if (pergAlt[5].intern() == "M") 
			{
				for(int j = 0; j < 5; j++)
					if(this.medias[j] == -1)
					{
						this.medias[j] = i;
						break;
					}
			} else if (pergAlt[5].intern() == "D")
			{
				for(int j = 0; j < 5; j++)
					if(this.dificeis[j] == -1)
					{
						this.dificeis[j] = i;
						break;
					}
			}
			this.nroPerguntas++;
		}
		
	}
	
	public void inserirPergunta(Pergunta p) {
		if(nroPerguntas == limitePerguntas)
			throw new IllegalArgumentException();
		
		arrayPerguntas[nroPerguntas] = p;
	}
	
	public void imprimirPerguntas() {
		
	}
}
