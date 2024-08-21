mensagem : string "F I M  D E  J O G O !"
novo_jogo : string "Jogar novamente? <Y/n>"

bool1: var #1
bool2: var #1
bool3: var #1
bool4: var #1
bool5: var #1
bool6: var #1

carta1:  var #1
carta2:  var #1
acertos: var #1

call ApagaTela
loadn R1, #tela0Linha0
loadn R2, #1792
call ImprimeTela0

jmp main

main:
	
	loadn r0, #0
	loadn r1, #0
	loadn r2, #0
	loadn r3, #0
	loadn r4, #0
	loadn r5, #0
	loadn r6, #0
	loadn r7, #3
	
	store carta1,  r0
	store carta2,  r0
	store acertos, r0
	
	store bool1,  r0
	store bool2,  r0
	store bool3,  r0
	store bool4,  r0
	store bool5,  r0
	store bool6,  r0
	
	jogar:
	
		load r6, acertos
		loadn r7, #3
		
		cmp r6, r7
		jeq fimGame
	
		call Loop
	
	halt
	
Loop:
	
	call jogar_carta1

	jmp Loop

jogar_carta1:

	jogar_carta1_loop:
	
		loadn r0, #0
		inchar r0
		store carta1, r0
		
		loadn r1, #49
		cmp r0, r1
		loadn r1, #t1Linha0
		loadn r7, #0
		loadn r2, #512
		jeq revelar_carta1
		
		loadn r1, #50
		cmp r0, r1
		loadn r1, #q1Linha0
		loadn r7, #0
		loadn r2, #3328
		jeq revelar_carta1
		
		loadn r1, #51
		cmp r0, r1
		loadn r1, #x1Linha0
		loadn r7, #0
		loadn r2, #3072
		jeq revelar_carta1
		
		loadn r1, #52
		cmp r0, r1
		loadn r1, #x2Linha0
		loadn r7, #1
		loadn r2, #3072
		jeq revelar_carta1
		
		loadn r1, #53
		cmp r0, r1
		loadn r1, #t2Linha0
		loadn r7, #1
		loadn r2, #512
		jeq revelar_carta1
		
		loadn r1, #54
		cmp r0, r1
		loadn r1, #q2Linha0
		loadn r7, #1
		loadn r2, #3328
		jeq revelar_carta1
		
	jmp jogar_carta1_loop

revelar_carta1:

	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7

	jmp verifica_virado1
	
	carta1_continuar:
	
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	
	call ImprimeCarta
	jmp jogar_carta2

jogar_carta2:
	
	loadn r0, #0
	load r4, carta1

	jogar_carta2_loop:
		
		loadn r0, #0
		inchar r0
		store carta2, r0
		
		cmp r0, r4
		jeq jogar_carta2_loop
		
		loadn r1, #49
		cmp r0, r1
		loadn r1, #t1Linha0
		loadn r7, #0
		loadn r2, #512
		jeq revelar_carta2
		
		loadn r1, #50
		cmp r0, r1
		loadn r1, #q1Linha0
		loadn r7, #0
		loadn r2, #3328
		jeq revelar_carta2
		
		loadn r1, #51
		cmp r0, r1
		loadn r1, #x1Linha0
		loadn r7, #0
		loadn r2, #3072
		jeq revelar_carta2
		
		loadn r1, #52
		cmp r0, r1
		loadn r1, #x2Linha0
		loadn r7, #1
		loadn r2, #3072
		jeq revelar_carta2
		
		loadn r1, #53
		cmp r0, r1
		loadn r1, #t2Linha0
		loadn r7, #1
		loadn r2, #512
		jeq revelar_carta2
		
		loadn r1, #54
		cmp r0, r1
		loadn r1, #q2Linha0
		loadn r7, #1
		loadn r2, #3328
		jeq revelar_carta2
		
	jmp jogar_carta2_loop
	
	halt

revelar_carta2:

	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7

	jmp verifica_virado2
	
	carta2_continuar:
	
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	
	call ImprimeCarta
	jmp pontuacao

verifica_virado1:

	loadn r0, #49
	load r1, carta1
	
	cmp r0, r1		; == 49 (int 1)
	jeq verifica_carta1_1
	
	inc r0
	cmp r0, r1		; == 50 (int 2)
	jeq verifica_carta1_2
	
	inc r0
	cmp r0, r1		; == 51 (int 3)
	jeq verifica_carta1_3
	
	inc r0
	cmp r0, r1		; == 52 (int 4)
	jeq verifica_carta1_4
	
	inc r0
	cmp r0, r1		; == 53 (int 5)
	jeq verifica_carta1_5
	
	inc r0
	cmp r0, r1		; == 54 (int 6)
	jeq verifica_carta1_6

	jmp ERRO
	
	;	x  y  z
	;	z  x  y
	;
	;	49 50 51
	;	52 53 54

	verifica_carta1_1:
	
		loadn r0, #1
		load r2, bool1
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
		
	verifica_carta1_2:
	
		loadn r0, #1
		load r2, bool2
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
	
	verifica_carta1_3:
	
		loadn r0, #1
		load r2, bool3
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
		
	verifica_carta1_4:
	
		loadn r0, #1
		load r2, bool4
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
		
	verifica_carta1_5:
	
		loadn r0, #1
		load r2, bool5
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
		
	verifica_carta1_6:
	
		loadn r0, #1
		load r2, bool6
		cmp r0, r2
		
		jeq verificar_sair_repetir1
		jne verificar_sair1
	
	verificar_sair1:

	 jmp carta1_continuar
	
	verificar_sair_repetir1:
	
		pop r7
		pop r6
		pop r5
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0
	
	jmp jogar_carta1_loop
	
verifica_virado2:

	loadn r0, #49
	load r1, carta2
	
	cmp r0, r1		; == 49 (int 1)
	jeq verifica_carta2_1
	
	inc r0
	cmp r0, r1		; == 50 (int 2)
	jeq verifica_carta2_2
	
	inc r0
	cmp r0, r1		; == 51 (int 3)
	jeq verifica_carta2_3
	
	inc r0
	cmp r0, r1		; == 52 (int 4)
	jeq verifica_carta2_4
	
	inc r0
	cmp r0, r1		; == 53 (int 5)
	jeq verifica_carta2_5
	
	inc r0
	cmp r0, r1		; == 54 (int 6)
	jeq verifica_carta2_6

	jmp ERRO
	
	;	x  y  z
	;	z  x  y
	;
	;	49 50 51
	;	52 53 54

	verifica_carta2_1:
	
		loadn r0, #1
		load r2, bool1
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
		
	verifica_carta2_2:
	
		loadn r0, #1
		load r2, bool2
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
	
	verifica_carta2_3:
	
		loadn r0, #1
		load r2, bool3
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
		
	verifica_carta2_4:
	
		loadn r0, #1
		load r2, bool4
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
		
	verifica_carta2_5:
	
		loadn r0, #1
		load r2, bool5
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
		
	verifica_carta2_6:
	
		loadn r0, #1
		load r2, bool6
		cmp r0, r2
		
		jeq verificar_sair_repetir2
		jne verificar_sair2
	
	verificar_sair2:

	 jmp carta2_continuar
	
	verificar_sair_repetir2:
	
		pop r7
		pop r6
		pop r5
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0
	
	jmp jogar_carta2_loop

pontuacao:

	loadn r0, #49
	load  r1, carta1
	load  r2, carta2
	load  r3, acertos
	
	cmp r0, r1		; == 49 (int 1)
	jeq carta1_1
	
	inc r0
	cmp r0, r1		; == 50 (int 2)
	jeq carta1_2
	
	inc r0
	cmp r0, r1		; == 51 (int 3)
	jeq carta1_3
	
	inc r0
	cmp r0, r1		; == 52 (int 4)
	jeq carta1_4
	
	inc r0
	cmp r0, r1		; == 53 (int 5)
	jeq carta1_5
	
	inc r0
	cmp r0, r1		; == 54 (int 6)
	jeq carta1_6
	
	jmp forcar_parada
	
	;	x  y  z
	;	z  x  y
	;
	;	49 50 51
	;	52 53 54
	
	;	53 54 52
	;	51 49 50
	
	carta1_1:
	
		loadn r0, #53
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool1, r0
		store bool5, r0
		
		jmp somar_acerto
		
	carta1_2:
	
		loadn r0, #54
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool2, r0
		store bool6, r0
		
		jmp somar_acerto
	
	carta1_3:
	
		loadn r0, #52
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool3, r0
		store bool4, r0
		
		jmp somar_acerto
		
	carta1_4:
	
		loadn r0, #51
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool3, r0
		store bool4, r0
		
		jmp somar_acerto
		
	carta1_5:
	
		loadn r0, #49
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool1, r0
		store bool5, r0
		
		jmp somar_acerto
		
	carta1_6:
	
		loadn r0, #50
		cmp r0, r2
		
		jne esconder_cartas
		
		loadn r0, #1
		store bool2, r0
		store bool6, r0
		
		jmp somar_acerto
		
	somar_acerto: 
	
		inc r3
		store acertos, r3
		jmp jogar

fimGame:

	loadn r0, #569		; posicao na tela
	loadn r1, #mensagem ; ponteiro para mensagem
	loadn r2, #256		; cor da mensagem

	Imprimestr1:	;  Rotina de Impresao de Mensagens:    r0 = Posicao da tela que o primeiro caractere da mensagem sera' impresso;  r1 = endereco onde comeca a mensagem; r2 = cor da mensagem.   Obs: a mensagem sera' impressa ate' encontrar "/0"
		
		loadn r3, #'\0'	; Criterio de parada

		ImprimestrLoop1:

			loadi r4, r1
			cmp r4, r3
			jeq loop_fim
			add r4, r2, r4
			outchar r4, r0
			inc r0
			inc r1
			
		jmp ImprimestrLoop1
			
			
	Imprimestr2:	;  Rotina de Impresao de Mensagens:    r0 = Posicao da tela que o primeiro caractere da mensagem sera' impresso;  r1 = endereco onde comeca a mensagem; r2 = cor da mensagem.   Obs: a mensagem sera' impressa ate' encontrar "/0"
		
		loadn r0, #608		; posicao na tela
		loadn r1, #novo_jogo ; ponteiro para mensagem
		loadn r2, #2816		; cor da mensagem
	
		loadn r3, #'\0'	; Criterio de parada

		ImprimestrLoop2:

			loadi r4, r1
			cmp r4, r3
			jeq loop_fim
			add r4, r2, r4
			outchar r4, r0
			inc r0
			inc r1
			
		jmp ImprimestrLoop2
			
		loop_fim:	
			
			jmp ERRO

ImprimeTela0:

	push r0	; protege o r3 na pilha para ser usado na subrotina
	push r1	; protege o r1 na pilha para preservar seu valor
	push r2	; protege o r1 na pilha para preservar seu valor
	push r3	; protege o r3 na pilha para ser usado na subrotina
	push r4	; protege o r4 na pilha para ser usado na subrotina
	push r5	; protege o r5 na pilha para ser usado na subrotina
	push r6	; protege o r6 na pilha para ser usado na subrotina

	loadn r0, #0  	; posicao inicial tem que ser o comeco da tela!
	loadn r3, #40  	; Incremento da posicao da tela!
	loadn r4, #41  	; incremento do ponteiro das linhas da tela
	loadn r5, #1200 ; Limite da tela!
	loadn r6, #tela0Linha0	; Endereco onde comeca a primeira linha do cenario!!
	
   ImprimeTela0_Loop:
		call ImprimeStr0
		add r0, r0, r3  	; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r1, r1, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		add r6, r6, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		cmp r0, r5			; Compara r0 com 1200
		jne ImprimeTela0_Loop	; Enquanto r0 < 1200

	pop r6	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts

ImprimeStr0:
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
	
	loadn r3, #'\0'
	loadn r5, #' '

   ImprimeStr0_Loop:
   		
		loadi r4, r1
		cmp r4, r3		; If (Char == \0)  vai Embora
		jeq ImprimeStr0_Sai
		cmp r4, r5		; If (Char == ' ')  vai Pula outchar do espaco para na apagar outros caracteres
		jeq ImprimeStr0_Skip
		add r4, r2, r4	; Soma a Cor
		outchar r4, r0	; Imprime o caractere na tela
   		storei r6, r4
   ImprimeStr0_Skip:
   call delayTela
		inc r0			; Incrementa a posicao na tela
		inc r1			; Incrementa o ponteiro da String
		inc r6
			
		jmp ImprimeStr0_Loop
	
   ImprimeStr0_Sai:	
	pop r6	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
ApagaTela:
	push r0
	push r1
	
	loadn r0, #1200		; apaga as 1200 posicoes da Tela
	loadn r1, #' '		; com "espaco"
	
	   ApagaTela_Loop:	;;label for(r0=1200;r3>0;r3--)
		dec r0
		outchar r1, r0
		jnz ApagaTela_Loop
 
	pop r1
	pop r0
	rts	

delayTela:
	
	push r0
	push r1
	
	loadn r1, #3  ; a
   	
   	delay_volta2:				;Quebrou o contador acima em duas partes (dois loops de decremento)
	
		loadn r0, #100	; b
		
   		delay_volta: 
   		
			dec r0					; (4*a + 6)b = 1000000  == 1 seg  em um clock de 1MHz
			jnz delay_volta	
			dec r1
			jnz delay_volta2
		
			pop r1
			pop r0
	
			rts	

delay:
	
	push r0
	push r1
	
	loadn r1, #100  ; a
   	
   	carta_delay_volta2:				;Quebrou o contador acima em duas partes (dois loops de decremento)
	
		loadn r0, #30000	; b
		
   		carta_delay_volta: 
   		
			dec r0					; (4*a + 6)b = 1000000  == 1 seg  em um clock de 1MHz
			jnz carta_delay_volta	
			dec r1
			jnz carta_delay_volta2
		
			pop r1
			pop r0
	
			rts	

ImprimeCarta:

	; r1 = endereco onde comeca a primeira linha do Cenario
	; r2 = cor do Cenario para ser impresso

	loadn r3, #40  ; Incremento da posicao da tela!
	loadn r4, #41  	; incremento do ponteiro das linhas da tela
	
	loadn r0, #1
	cmp r0, r7
	jeq set_linha1

	loadn r0, #120  	; posicao inicial tem que ser o comeco da tela!
	loadn r5, #520 ; Limite da tela!
	loadn r6, #tela0Linha0	; Endereco onde comeca a primeira linha do cenario!!
	jmp ImprimeTela1_Loop
	
	set_linha1:
		
		loadn r0, #680  	; posicao inicial tem que ser o comeco da tela!
		loadn r5, #1080 ; Limite da tela!
		loadn r6, #tela0Linha0
	
   ImprimeTela1_Loop:
		call ImprimeStr1
		add r0, r0, r3  	; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r1, r1, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		add r6, r6, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		cmp r0, r5			; Compara r0 com 1200
		jne ImprimeTela1_Loop	; Enquanto r0 < 1200

	rts

ImprimeStr1:	;  Rotina de Impresao de Mensagens:    r0 = Posicao da tela que o primeiro caractere da mensagem sera' impresso;  r1 = endereco onde comeca a mensagem; r2 = cor da mensagem.   Obs: a mensagem sera' impressa ate' encontrar "/0"
	push r0	; protege o r0 na pilha para preservar seu valor
	push r1	; protege o r1 na pilha para preservar seu valor
	push r2	; protege o r1 na pilha para preservar seu valor
	push r3	; protege o r3 na pilha para ser usado na subrotina
	push r4	; protege o r4 na pilha para ser usado na subrotina
	push r5	; protege o r5 na pilha para ser usado na subrotina
	push r6	; protege o r6 na pilha para ser usado na subrotina
	
	
	loadn r3, #'\0'	; Criterio de parada
	loadn r5, #' '	; Espaco em Branco

   ImprimeStr1_Loop:
   		
		loadi r4, r1
		cmp r4, r3		; If (Char == \0)  vai Embora
		jeq ImprimeStr1_Sai
		cmp r4, r5		; If (Char == ' ')  vai Pula outchar do espaco para na apagar outros caracteres
		jeq ImprimeStr1_Skip
		add r4, r2, r4	; Soma a Cor
		outchar r4, r0	; Imprime o caractere na tela
   		storei r6, r4
   ImprimeStr1_Skip:
   call delayTela
		inc r0			; Incrementa a posicao na tela
		inc r1			; Incrementa o ponteiro da String
		inc r6
			
		jmp ImprimeStr1_Loop
	
   ImprimeStr1_Sai:	
	pop r6	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r5
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
	
esconder_cartas:

	load r0, carta1
	call apagar_carta
	
	load r0, carta2
	call apagar_carta
	
	;jmp ERRO

apagar_carta:
	;jmp fimGame
	
	loadn r1, #49
	cmp r0, r1
	loadn r1, #t1Linha0
	loadn r7, #0
	loadn r2, #3840
	jeq ImprimeCarta
	
	loadn r1, #50
	cmp r0, r1
	loadn r1, #q1Linha0
	loadn r7, #0
	loadn r2, #3840
	jeq ImprimeCarta
	
	loadn r1, #51
	cmp r0, r1
	loadn r1, #x1Linha0
	loadn r7, #0
	loadn r2, #3840
	jeq ImprimeCarta
	
	loadn r1, #52
	cmp r0, r1
	loadn r1, #x2Linha0
	loadn r7, #1
	loadn r2, #3840
	jeq ImprimeCarta
	
	loadn r1, #53
	cmp r0, r1
	loadn r1, #t2Linha0
	loadn r7, #1
	loadn r2, #3840
	jeq ImprimeCarta
	
	loadn r1, #54
	cmp r0, r1
	loadn r1, #q2Linha0
	loadn r7, #1
	loadn r2, #3840
	jeq ImprimeCarta
	
	rts

apagar_carta:
	
	loadn r3, #40  ; Incremento da posicao da tela!
	loadn r4, #41  	; incremento do ponteiro das linhas da tela
	
	loadn r0, #1
	cmp r0, r7
	jeq set_linha1

	loadn r0, #120  	; posicao inicial tem que ser o comeco da tela!
	loadn r5, #520 ; Limite da tela!
	loadn r6, #tela0Linha0	; Endereco onde comeca a primeira linha do cenario!!
	jmp ImprimeTela1_Loop
	
	set_linha1:
		
		loadn r0, #680  	; posicao inicial tem que ser o comeco da tela!
		loadn r5, #1080 ; Limite da tela!
		loadn r6, #tela0Linha0
	
   ImprimeTela1_Loop:
		call ImprimeStr1
		add r0, r0, r3  	; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r1, r1, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		add r6, r6, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		cmp r0, r5			; Compara r0 com 1200
		jne ImprimeTela1_Loop	; Enquanto r0 < 1200

	rts

	jmp forcar_parada

tela0Linha0  : string "                                        "
tela0Linha1  : string "                                        "
tela0Linha2  : string " +----------+ +----------+ +----------+ "
tela0Linha3  : string " |          | |          | |          | "
tela0Linha4  : string " |          | |          | |          | "
tela0Linha5  : string " |          | |          | |          | "
tela0Linha6  : string " |          | |          | |          | "
tela0Linha7  : string " |          | |          | |          | "
tela0Linha8  : string " |          | |          | |          | "
tela0Linha9  : string " |          | |          | |          | "
tela0Linha10 : string " |          | |          | |          | "
tela0Linha11 : string " |          | |          | |          | "
tela0Linha12 : string " |          | |          | |          | "
tela0Linha13 : string " +----------+ +----------+ +----------+ "
tela0Linha14 : string "                                        "
tela0Linha15 : string "                                        "
tela0Linha16 : string " +----------+ +----------+ +----------+ "
tela0Linha17 : string " |          | |          | |          | "
tela0Linha18 : string " |          | |          | |          | "
tela0Linha19 : string " |          | |          | |          | "
tela0Linha20 : string " |          | |          | |          | "
tela0Linha21 : string " |          | |          | |          | "
tela0Linha22 : string " |          | |          | |          | "
tela0Linha23 : string " |          | |          | |          | "
tela0Linha24 : string " |          | |          | |          | "
tela0Linha25 : string " |          | |          | |          | "
tela0Linha26 : string " |          | |          | |          | "
tela0Linha27 : string " +----------+ +----------+ +----------+ "
tela0Linha28 : string "                                        "
tela0Linha29 : string "                                        "

t1Linha0  : string "                                        "
t1Linha1  : string "      xx                                "
t1Linha2  : string "     xxxx                               "
t1Linha3  : string "    xx  xx                              "
t1Linha4  : string "    xx  xx                              "
t1Linha5  : string "   xx    xx                             "
t1Linha6  : string "   xx    xx                             "
t1Linha7  : string "  xx      xx                            "
t1Linha8  : string "  xx      xx                            "
t1Linha9  : string "  xxxxxxxxxx                            "

t2Linha0  : string "                                        "
t2Linha1  : string "                   xx                   "
t2Linha2  : string "                  xxxx                  "
t2Linha3  : string "                 xx  xx                 "
t2Linha4  : string "                 xx  xx                 "
t2Linha5  : string "                xx    xx                "
t2Linha6  : string "                xx    xx                "
t2Linha7  : string "               xx      xx               "
t2Linha8  : string "               xx      xx               "
t2Linha9  : string "               xxxxxxxxxx               "




q1Linha0  : string "               xxxxxxxxxx               "
q1Linha1  : string "               xxxxxxxxxx               "
q1Linha2  : string "               xx      xx               "
q1Linha3  : string "               xx      xx               "
q1Linha4  : string "               xx      xx               "
q1Linha5  : string "               xx      xx               "
q1Linha6  : string "               xx      xx               "
q1Linha7  : string "               xx      xx               "
q1Linha8  : string "               xxxxxxxxxx               "
q1Linha9  : string "               xxxxxxxxxx               "

q2Linha0  : string "                            xxxxxxxxxx  "
q2Linha1  : string "                            xxxxxxxxxx  "
q2Linha2  : string "                            xx      xx  "
q2Linha3  : string "                            xx      xx  "
q2Linha4  : string "                            xx      xx  "
q2Linha5  : string "                            xx      xx  "
q2Linha6  : string "                            xx      xx  "
q2Linha7  : string "                            xx      xx  "
q2Linha8  : string "                            xxxxxxxxxx  "
q2Linha9  : string "                            xxxxxxxxxx  "


x1Linha0  : string "                                        "
x1Linha1  : string "                            xx      xx  "
x1Linha2  : string "                             xx    xx   "
x1Linha3  : string "                              xx  xx    "
x1Linha4  : string "                               xxxx     "
x1Linha5  : string "                               xxxx     "
x1Linha6  : string "                              xx  xx    "
x1Linha7  : string "                             xx    xx   "
x1Linha8  : string "                            xx      xx  "
x1Linha9  : string "                                        "

x2Linha0  : string "                                        "
x2Linha1  : string "  xx      xx                            "
x2Linha2  : string "   xx    xx                             "
x2Linha3  : string "    xx  xx                              "
x2Linha4  : string "     xxxx                               "
x2Linha5  : string "     xxxx                               "
x2Linha6  : string "    xx  xx                              "
x2Linha7  : string "   xx    xx                             "
x2Linha8  : string "  xx      xx                            "
x2Linha9  : string "                                        "

debug : string "debuggg"

forcar_parada:

	call ApagaTela
	
ERRO:

	loadn r0, #0
	loadn r1, #debug
	loadn r2, #256
	
	;call print_erro
	
	load r0, carta1
	load r1, bool1
	load r2, bool2
	load r3, bool3
	load r4, bool4
	load r5, bool5
	load r6, bool6
	load r7, carta2
	
	halt

print_erro:
	
	loadn r3, #'\0'	; Criterio de parada

erro_loop:	
	loadi r4, r1
	cmp r4, r3
	jeq erro_sai
	add r4, r2, r4
	outchar r4, r0
	inc r0
	inc r1
	jmp erro_loop
	
erro_sai:	
	
	rts
