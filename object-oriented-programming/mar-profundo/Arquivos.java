import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.io.FileWriter;
import java.io.IOException;

public class Arquivos {
	public static String[] lerPerguntas(String fileName)
	{
		int wordCount = 0; 
		String perguntasString[] = new String[100];
			
		try {
		  File myObj = new File("Datasets/"+ fileName + ".csv");
		  Scanner myReader = new Scanner(myObj);
		  while (myReader.hasNextLine()) {
		    String data = myReader.nextLine();
		    perguntasString[wordCount++] = data;
		  }
		  myReader.close();
		} catch (FileNotFoundException e) {
		  System.out.println("An error occurred.");
		  e.printStackTrace();
		}
		
		return perguntasString;
	}
	
	public static String[] lerPlacar() 
	{
		int wordCount = 0; 
		String placarString[] = new String[100];
			
		try {
		  File myObj = new File("placar.csv");
		  Scanner myReader = new Scanner(myObj);
		  while (myReader.hasNextLine()) {
		    String data = myReader.nextLine();
		    placarString[wordCount++] = data;
		  }
		  myReader.close();
		} catch (FileNotFoundException e) {
		  System.out.println("An error occurred.");
		  e.printStackTrace();
		}
		
		return placarString;
	}
  
	
	
	public void addPessoaPlacar(Placar atual) {			
		String linesStrings[] = lerPlacar();
		String antigoPlacar[] =  linesStrings[0].split(Pattern.quote(",")); //pegar os nomes e os pontos
		String novoPlacar[] = new String[10];
		
		for (int i = 0; i < antigoPlacar.length; i++)
		{
			String dados[] =  antigoPlacar[i].split(Pattern.quote(" ")); //separar os nomes dos pontos
			if(Integer.parseInt(dados[2]) < atual.getPlacar())
			{
				System.out.print(dados[0] + " é maior que teste\n");
				if (i > 9)
					return; //Não insere pois é maior que o limite
				for (int j = 0; j < i; j++)
				{
					novoPlacar[j] = antigoPlacar[j]; //Seta até a posição que deve inserir
				}
				//Insere na posição correta
				novoPlacar[i] = atual.getUserName() + " - " + Integer.toString(atual.getPlacar()) + " pontos";
				for (int j = i+1; j < antigoPlacar.length+1; j++)
				{
					novoPlacar[j] = antigoPlacar[i]; //Coloca o resto
					System.out.print(novoPlacar[j]+"\n");
					i++;
				}
			}
		}
		
		try {
			FileWriter myWriter = new FileWriter("placar.csv");
			for(int i=0; i<10; i++) {
				if(novoPlacar[i] != null) {
					myWriter.write(novoPlacar[i]+",");
				}			
			}
			myWriter.close();	
		} catch (IOException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
	  }
	
	public static void writeFile(String fileName, String lineStrings[]) {			
		try {
			FileWriter myWriter = new FileWriter(fileName);
			for(int i=0; i<100; i++) {
				if(lineStrings[i] != null) {
					myWriter.write(lineStrings[i]);
				}			
			}
			myWriter.close();	
		} catch (IOException e) {
			System.out.println("An error occurred.");
			e.printStackTrace();
		}
	  }
	
}

