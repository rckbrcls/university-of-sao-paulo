/**
 * Classe pessoa fisica filha da classe pessoa
 * @author Erick Barcelos (11345562)
 *
 */
public class PessoaFisica extends Pessoa{ 
	
	private String CPF;
	private String dataDeNascimento;
	private String estadoCivil;
	/**
	 * Construtor da classe pessoa fisica
	 * @param n
	 * @param end
	 * @param mail
	 * @param c
	 * @param d
	 * @param ec
	 */
	public PessoaFisica (String n, String end, String mail, String c, String d, String ec) {
		super(n, end, mail);
		CPF = c;
		dataDeNascimento = d;
		estadoCivil = ec;
	}
	/**
	 * Retorna o CPF
	 * @return
	 */
	public String getCPF() {
		return CPF;
	}
	/**
	 * Atribui CPF
	 * @param c
	 */
	public void setCPF(String c) {
		this.CPF = c;
	}
	/**
	 * Retorna a data de nascimento
	 * @return
	 */
	public String getDataDeNascimento() {
		return dataDeNascimento;
	}
	/**
	 * Atribui data de nascimento
	 * @param d
	 */
	public void setDataDeNascimento(String d) {
		this.dataDeNascimento = d;
	}
	/**
	 * Retorna o estado civil
	 * @return
	 */
	public String getEstadoCivil() {
		return estadoCivil;
	}
	/**
	 * Atribui estado civil
	 * @param ec
	 */
	public void setEstadoCivil(String ec) {
		this.estadoCivil = ec;
	}
}
