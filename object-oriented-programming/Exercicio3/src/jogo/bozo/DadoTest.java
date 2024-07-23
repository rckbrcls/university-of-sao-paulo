package jogo.bozo;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class DadoTest {
	
	private Dado dado;

	@Before
	public void setUp() throws Exception {
		dado = new Dado();
	}
	
	@Before
	public void setUp2() throws Exception {
		dado = new Dado(6);
	}

	@After
	public void tearDown() throws Exception {
		dado = null;
	}
	
	@Test
	public void testGetLado() {
		int test = dado.getLado();
		assertTrue(test >= 1 && test <=6);		
	}

	@Test
	public void testRolar1() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1) {
				fail("ERRO! Número de lados incorreto.");
				break;
			}
		
			if(test == 1) {
				assertEquals(test, 1);
				break;
			}
		}
	
		
	}
	@Test
	public void testRolar2() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1){
				fail("ERRO! Número de lados incorreto.");
				break;
			}
			
			if(test == 2) {
				assertEquals(test, 2);
				break;
			}
		}
	
	}
	@Test
	public void testRolar3() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1){
				fail("ERRO! Número de lados incorreto.");
				break;
			}
			
			if(test == 3) {
				assertEquals(test, 3);
				break;
			}
		}
	
	}
	@Test
	public void testRolar4() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1){
				fail("ERRO! Número de lados incorreto.");
				break;
			}
			
			if(test == 4) {
				assertEquals(test, 4);
				break;
			}
			
		}
	
	}
	@Test
	public void testRolar5() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1){
				fail("ERRO! Número de lados incorreto.");
				break;
			}
			
			if(test == 5) {
				assertEquals(test, 5);
			break;
			}
		}
	
	}
	@Test
	public void testRolar6() {
		int test = 1;
		
		while(true) {
			test = dado.rolar();
			
			if(test > 6 || test < 1){
				fail("ERRO! Número de lados incorreto.");
				break;
			}
			
			if(test == 6) {
				assertEquals(test, 6);
				break;
			}
		}
	
	}

	@Test
	public void testToString1() {
		String r = "+-----+\n|     |\n|  *  |\n|     |\n+-----+\n";
		dado.ladoSuperior = 1;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString2() {
		String r = "+-----+\n|    *|\n|     |\n|*    |\n+-----+\n";
		dado.ladoSuperior = 2;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString3() {
		String r = "+-----+\n|    *|\n|  *  |\n|*    |\n+-----+\n";
		dado.ladoSuperior = 3;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString4() {
		String r = "+-----+\n|*   *|\n|     |\n|*   *|\n+-----+\n";
		dado.ladoSuperior = 4;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString5() {
		String r = "+-----+\n|*   *|\n|  *  |\n|*   *|\n+-----+\n";
		dado.ladoSuperior = 5;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString6() {
		String r = "+-----+\n|*   *|\n|*   *|\n|*   *|\n+-----+\n";
		dado.ladoSuperior = 6;
		assertEquals(dado.toString(), r);
	}
	
	@Test
	public void testToString7() {
		String r = "";
		dado.ladoSuperior = 7;
		assertEquals(dado.toString(), r);
	}

}
