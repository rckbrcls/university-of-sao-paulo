import java.io.IOException;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/** Classe agenda que manipula
 * os contatos (pessoas fisicas ou juridicas),
 * como insere, remove, ordena e imprime
 * @author Erick Barcelos (11345562)
 */
public class Agenda {
	private int MAX = 100; // Numero maximo de contatos
	private Pessoa contatos[] = new Pessoa[MAX]; // Vetor que armazena os contatos
	private int nPessoas = 0; // Numero de pessoas
	
	/**
	 * Metodo principal do programa que faz a selecao de qual operacao deve ser feita
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		Agenda ag = new Agenda();
		
		//Variaveis auxiliares
		int op = 0;
		String s1 = new String();
		String s2= new String();
		String s3 = new String();
		String s4 = new String();
		String s5 = new String();
		String s6 = new String();
		
		// Selecionas as operacoes
		while (op != 7) {
			op = ag.leOpcao();
			switch (op){
				case 1:// Insere pessoa fisica
					System.out.println("Entre com o nome: \n");
					s1 = EntradaTeclado.leString();
					
					System.out.println("Entre com o endereco: \n");
					s2 = EntradaTeclado.leString();
					
					System.out.println("Entre com o e-mail (example_10@testmail.com.br): \n");
					
					for(;;){
						s3 = EntradaTeclado.leString();
						
						if(ag.verificaEmail(s3))
							break;
						else
							System.out.println("E-mail invalido, digite de novo: \n");
					}
					
					System.out.println("Entre com o CPF (000.000.000-00): \n");
					
					for(;;) {
						s4 = EntradaTeclado.leString();
						
						if(ag.verificaCPF(s4))
							break;
						else
							System.out.println("CPF invalido, digite de novo: \n");
					}
						
					System.out.println("Entre com a data de nascimento (dd/mm/yyyy): \n");
					
					for(;;) {
						s5 = EntradaTeclado.leString();
						
						if(ag.verificaDataDeNascimento(s5))
							break;
						else
							System.out.println("Data invalida, digite de novo: \n");
					}
		
					System.out.println("Entre com o estado civil (solteiro, casado e etc.): \n");
					s6 = EntradaTeclado.leString();
					
					PessoaFisica pf = new PessoaFisica(s1, s2, s3, s4, s5, s6);
					ag.addContato(pf);
		
					break;
				case 2: // Insere pessoa juridica
					System.out.println("Entre com o nome: \n");
					s1 = EntradaTeclado.leString();
					
					System.out.println("Entre com o endereco: \n");
					s2 = EntradaTeclado.leString();
					
					System.out.println("Entre com o e-mail (example_10@testmail.com.br): \n");
					
					for(;;){
						s3 = EntradaTeclado.leString();
						
						if(ag.verificaEmail(s3))
							break;
						else
							System.out.println("E-mail invalido, digite de novo: \n");
					}
					
					System.out.println("Entre com o CNPJ (00.000.000/0000-00): \n");
					
					for(;;) {
						s4 = EntradaTeclado.leString();
						
						if(ag.verificaCNPJ(s4))
							break;
						else
							System.out.println("CNPJ invalido, digite de novo: \n");
					}
						
					System.out.println("Entre com a inscricao estadual: \n");
					s5 = EntradaTeclado.leString();
						
					System.out.println("Entre com a razao social: \n");
					s6 = EntradaTeclado.leString();
					
					PessoaJuridica pj = new PessoaJuridica(s1, s2, s3, s4, s5, s6);
					ag.addContato(pj);
				
					break;
				case 3: // Remove contato
					System.out.println("Entre com o CPF/CNPJ ou nome da pessoa que voce deseja remover: \n");
					s1 = EntradaTeclado.leString();
					ag.removeContato(s1);
					break;
				case 4: // Imprime todos os contatos
					System.out.println("Todos contatos: \n");
					ag.imprimirTodosContatos();
					break;
				case 5: // Procura um contato
					System.out.println("Entre com o CPF/CNPJ ou nome da pessoa que voce deseja procurar: \n");
					s1 = EntradaTeclado.leString();
					Pessoa p = ag.busca(s1);
					
					if(p != null) {
						System.out.println("O contato procurado: \n");
						ag.imprimirContato(p);
					}
					
					break;
				case 6: // Ordena a lista de contatos
					System.out.println("Ordenando...\n");
					ag.ordenacao();
					System.out.println("Todos contatos depois de ordenados: \n");
					ag.imprimirTodosContatos();
					break;
			}
		}
	}
	/**
	 * Le a opcao que o usuario selecionou
	 * @return
	 */
	private int leOpcao() {
        System.out.println("1) Adicionar pessoa fisica\n2) Adicionar pessoa juridica\n3) Remover contato\n4) Imprimir todos\n"
        		+ "5) Procurar contato\n6) Ordenar agenda\n7) Sair");
        int k = -1;
        
        while (true)
        {
        	System.out.println("Digite a opcao desejada ===> ");
        	try {
        		k = EntradaTeclado.leInt();
        		if ( k > 0 && k < 8 )
        			return k;
        	}
        	catch (Exception e) {
        		;
        	}
        }
	}
	/**
	 * Imprime somente um contato, antes verificando qual eh a classe que ele pertence
	 * @param p
	 */
	public void imprimirContato(Pessoa p) {
		System.out.println("-----------------------------");
		if ( p instanceof PessoaFisica ){ 
			PessoaFisica ct = (PessoaFisica) p;
			System.out.println("\nCPF: " + ct.getCPF());
			System.out.println("\nNome: " + ct.getNome());
			System.out.println("\nEndereço: " + ct.getEndereco());
			System.out.println("\nData de nascimento: " + ct.getDataDeNascimento());
			System.out.println("\nE-mail: " + ct.getEmail());
			System.out.println("\nEstado Civil: " + ct.getEstadoCivil());
		}else if ( p instanceof PessoaJuridica ) {
			PessoaJuridica ct = (PessoaJuridica) p;
			System.out.println("\nCNPJ: " + ct.getCNPJ());
			System.out.println("\nNome: " + ct.getNome());
			System.out.println("\nEndereço: " + ct.getEndereco());
			System.out.println("\nE-mail: " + ct.getEmail());
			System.out.println("\nInscrição Estadual: " + ct.getInscricaoEstadual());
			System.out.println("\nRazão Social: " + ct.getRazaoSocial());
		}
		System.out.println("-----------------------------");
	}
	/**
	 * Imprime todos os contatos da agenda, verifica
	 * se a primeira posicao do vetor contatos eh vazia,
	 * se for, a agenda esta vazia
	 */
	public void imprimirTodosContatos() {
		if (contatos[0] == null ) {
			System.out.println("Agenda vazia!");
			return;
		}
		
		for (Pessoa aux: contatos) {
			if ( aux == null ) break;
			imprimirContato(aux);
		}
	}
	/**
	 * Funcao que adiciona um contato para a agenda,
	 * caso o numero de pessoas seja o mesmo do maximo
	 * permitido, retorna que a agenda esta cheia
	 * @param p
	 */
	public void addContato (Pessoa p) {
		if (nPessoas == MAX) {
			System.out.println("Agenda cheia!");
			return;
		}
		
		contatos[nPessoas++] = p;
	}
	/**
	 * Remove contato a partir de uma string, que pode
	 * ser CPF/CNPJ ou um nome. Primeiro busca o index de onde a string
	 * esta no vetor, depois verifica se esta no final ou no incio/meio 
	 * do vetor, em seguida remove
	 * @param s
	 */
	public void removeContato(String s) {
		int pos = buscarIndexContato(s);
		
		if (pos == -1) // se nao achar
			return; 
        
		if(nPessoas == MAX)
			contatos = Arrays.copyOf(contatos, contatos.length-1); // copia a string menos uma posicao
		else
	        for (int i = pos; i < nPessoas; i++)
	            contatos[i] = contatos[i + 1]; // copia por cima
		
		nPessoas--;
		
		System.out.println("Contato removido com sucesso!");
	}
	/**
	 * Verifica se o CPF eh valido usando regex
	 * @param s
	 * @return
	 */
	public boolean verificaCPF(String s) {
		return s.matches("[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}");
	}
	/**
	 * Verifica se o CNPJ eh valido usando regex
	 * @param s
	 * @return
	 */
	public boolean verificaCNPJ(String s) {
		return s.matches("[0-9]{2}\\.?[0-9]{3}\\.?[0-9]{3}\\/?[0-9]{4}\\-?[0-9]{2}");
	}
	/**
	 * Verifica se a data de nascimento eh valida usando regex
	 * @param s
	 * @return
	 */
	public boolean verificaDataDeNascimento(String s) {
		return s.matches("[0-9]{2}//?[0-9]{2}//?[0-9]{4}");
	}
	/**
	 * Verifica se o e-mail eh valido usando regex
	 * @param s
	 * @return
	 */
	public boolean verificaEmail(String s) {
		Pattern emailRegex = Pattern.compile("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,6}$", Pattern.CASE_INSENSITIVE);
		Matcher matcher = emailRegex.matcher(s);
	    return matcher.find();
	}
	/**
	 * Faz a busca de um contato usando seu CPF/CNPJ ou nome,
	 * e retorna uma classe pessoa
	 * @param s
	 * @return
	 */
	public Pessoa busca(String s) {
		int indice = buscarIndexContato(s);
		
		if(indice > -1) 
			return contatos[indice];
		
		return null;
	}
	/**
	 * Busca o index de uma certa string no
	 * vetor contatos
	 * @param s
	 * @return
	 */
	public int buscarIndexContato(String s) {
		int i = 0;
		if(verificaCPF(s)) {// Verifica se a string eh CPF
			
			for (Pessoa aux: contatos) {
	
				if ( aux == null ) break;
	
				if ( aux instanceof PessoaFisica ){
					
					PessoaFisica ct = (PessoaFisica) aux;
					if(ct.getCPF().compareTo(s) == 0) 
						return i;
				}
				i++;
			}
		} else if(verificaCNPJ(s)){// Verifica se a string eh CNPJ
			
			for (Pessoa aux: contatos) {
				if ( aux == null ) break;
	
				if ( aux instanceof PessoaJuridica ){
					
					PessoaJuridica ct = (PessoaJuridica) aux;
					if(ct.getCNPJ().compareTo(s) == 0) 
						return i;
				}
				i++;
			}
		} else { // Se nao for nenhum dos dois pode ser nome
			for (Pessoa aux: contatos) {
				if ( aux == null ) break;

				if (aux.getNome().compareTo(s) == 0)
					return i;
				i++;
			}
		}
		
		// Se nao for nenhum dos tres, a string n foi achada
		System.out.println("Elemento não achado");
		
		return -1;
	}
	/**
	 * Funcao utilizada para pegar a ordem do index de cada classe,
	 * essa funcao eh usada para auxiliar na ordenacao do vetor, 
	 * botando as pessoas fisicas antes das pessoas juridicas
	 * @param p
	 * @return
	 */
	public int pegarOrdemIndex(Pessoa p) {
		if (p == null) 
            return 0;
        else if (p instanceof PessoaFisica) // Se for pessoa fisica, eh 1
            return 1;
        else if (p instanceof PessoaJuridica) // Se for pessoa juridica, eh 2
            return 2;
        else 
            throw new RuntimeException("Pessoas inesperada: " + p.getClass().getName());
	}
	/**
	 * Funcao que ordena o vetor contatos,
	 * usando um bubblesort modificado.
	 * Primeiro ele verifica se a ordem de index das posicoes
	 * eh diferente, caso seja, altera as posicoes. Caso as ordens
	 * sejam iguais, verifica se eh pessoa fisica ou juridica, logo
	 * em seguida compara os tamanhos e troca se necessario
	 */
	public void ordenacao() {
		
		for(int i = 1; i < nPessoas; i++) {  
			for (int j = 0; j < nPessoas-1; j++) {  
				int index1 = pegarOrdemIndex(contatos[j]);// pega a ordem das posicoes
		        int index2 = pegarOrdemIndex(contatos[j+1]);
		   
		        if(index1 > index2) { // se a ordem da posicao da frente for maior que a da seguida, faz a troca
		        	Pessoa temp = contatos[j];
		        	contatos[j] = contatos[j + 1];
		        	contatos[j + 1] = temp;
		        
		        }else if(index1 == index2) { // se as ordem forem iguais
		        	if ( index1 == 1 ){ // verifica se eh pessoa fisica
						
						PessoaFisica ct1 = (PessoaFisica) contatos[j];
						PessoaFisica ct2 = (PessoaFisica) contatos[j+1];
						
						if(ct1.getCPF().compareTo(ct2.getCPF()) > 0) { // compara os tamanhos das strings, se necessario, troca
							Pessoa temp = contatos[j];
				        	contatos[j] = contatos[j + 1];
				        	contatos[j + 1] = temp;
						}
							
				
		        	}else if( index2 == 2 ) {// verifica se eh pessoa juridica
		        		
		        		PessoaJuridica ct1 = (PessoaJuridica) contatos[j];
						PessoaJuridica ct2 = (PessoaJuridica) contatos[j+1];
						
						if(ct1.getCNPJ().compareTo(ct2.getCNPJ()) > 0) {  // compara os tamanhos das strings, se necessario, troca
							
							Pessoa temp = contatos[j];
				        	contatos[j] = contatos[j + 1];
				        	contatos[j + 1] = temp;
				        	
						}
		        	}
		        }
			}  
		}  
	}
}
