/**
 * Classe pai dos contatos da agenda
 * @author Erick Barcelos (11345562)
 *
 */
public class Pessoa {

	private String nome;
	private String endereco;
	private String email;
	/**
	 * Construtor da classe
	 * @param n
	 * @param end
	 * @param mail
	 */
	public Pessoa(String n, String end, String mail){
		nome = n;
		endereco = end;
		email = mail;
	}
	/**
	 * Retorna o nome
	 * @return 
	 */
	public String getNome() {
		return nome;
	}
	/**
	 * Atribui um nome
	 * @param n
	 */
	public void setNome(String n) {
		this.nome = n;
	}
	/**
	 * Retorna o endereco
	 * @return
	 */
	public String getEndereco() {
		return endereco;
	}
	/**
	 * Atribui um endereco
	 * @param end
	 */
	public void setEndereco(String end) {
		this.endereco = end;
	}
	/**
	 * Retorna o e-mail
	 * @return
	 */
	public String getEmail() {
		return email;
	}
	/**
	 * Atribui e-mail
	 * @param mail
	 */
	public void setEmail(String mail) {
		this.email = mail;
	}
	
}
