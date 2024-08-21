import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		
		String path = "Dataset-Biologia.csv";
	    BufferedReader buffRead = new BufferedReader(new FileReader(path));
			String linha = "";
			while (true) {
				if (linha != null) {
					System.out.println(linha);

				} else
					break;
				linha = buffRead.readLine();
			}
			buffRead.close();
		}

}
