/**
 * Classe pessoa juridica filha da classe pessoa
 * @author Erick Barcelos (11345562)
 *
 */
public class PessoaJuridica extends Pessoa {
	
	private String CNPJ;
	private String inscricaoEstadual;
	private String razaoSocial;

	/**
	 * Construtor da classe pessoa juridica
	 * @param n
	 * @param end
	 * @param mail
	 * @param c
	 * @param ic
	 * @param rs
	 */
	public PessoaJuridica (String n, String end, String mail, String c, String ic, String rs) {
		super(n, end, mail);
		CNPJ = c;
		inscricaoEstadual = ic;
		razaoSocial = rs;
	}
	/**
	 * Retorna o CNPJ
	 * @return
	 */
	public String getCNPJ() {
		return CNPJ;
	}
	/**
	 * Atribui o CNPJ
	 * @param c
	 */
	public void setCNPJ(String c) {
		this.CNPJ = c;
	}
	/**
	 * Retorna a inscricao estadual
	 * @return
	 */
	public String getInscricaoEstadual() {
		return inscricaoEstadual;
	}
	/**
	 * Atribui inscricao estadual
	 * @param ic
	 */
	public void setInscricaoEstadual(String ic) {
		this.inscricaoEstadual = ic;
	}
	/**
	 * Retorna a razao social
	 * @return
	 */
	public String getRazaoSocial() {
		return razaoSocial;
	}
	/**
	 * Atribui razao social
	 * @param rs
	 */
	public void setRazaoSocial(String rs) {
		this.razaoSocial = rs;
	}
}
