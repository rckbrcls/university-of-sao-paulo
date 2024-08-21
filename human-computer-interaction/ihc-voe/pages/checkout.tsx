import { ReactNode, useState } from 'react';
import { Button, TextField, Typography } from '@mui/material';
import { NextPage } from 'next';
import Link from 'next/link';
import Footer from '../components/footer';
import Header from '../components/header';
import ResumeCard from '../components/resumeCard';
import InputMask from 'react-input-mask';

const Checkout: NextPage = () => {
  const [CPF, setCPF] = useState('');
  const [Estado, setEstado] = useState('');
  const [Data, setData] = useState('');
  const [CVV, setCVV] = useState('');

  return (
    <>
      <Header />
      <ResumeCard />
      <div className="container m-auto">
        <form action="">
          <div className="row">
            <div className="col">
              <Typography variant="h3" className="title">
                Dados do Passageiro
              </Typography>

              <div className="flex mb-4 mx-4">
                <TextField
                  variant="outlined"
                  id="outlined-basic"
                  label="Nome"
                  placeholder="Digite seu nome completo"
                  className="bg-white rounded-xl w-full"
                />
              </div>
              <div className="flex mb-4 mx-4">
                {/* <TextField
                  type="number"
                  variant="outlined"
                  id="outlined-basic"
                  placeholder="CPF"
                  className="bg-white rounded-xl w-full"
                /> */}
                <InputMask
                  mask="999.999.999-99"
                  placeholder="Digite o seu CPF"
                  value={CPF}
                  onChange={(e) => setCPF(e.target.value)}
                >
                  <TextField
                    className="bg-white rounded-xl w-full"
                    id="outlined-basic"
                    label="CPF"
                    variant="outlined"
                  />
                </InputMask>
              </div>
              <div className="flex mb-4 mx-4">
                <TextField
                  type="email"
                  variant="outlined"
                  id="outlined-basic"
                  label="E-mail"
                  placeholder="exemplo@email.com"
                  className="bg-white rounded-xl w-full"
                />
              </div>
              <div className="flex mb-4 mx-4">
                <TextField
                  variant="outlined"
                  id="outlined-basic"
                  label="Endereço de cobrança"
                  placeholder="Digite seu endereço de cobrança"
                  className="bg-white rounded-xl w-full"
                />
              </div>

              <div className="flex flex-col lg:flex-row">
                <div className="flex flex-col lg:flex-row mb-4 mx-4">
                  <TextField
                    variant="outlined"
                    id="outlined-basic"
                    label="Cidade"
                    placeholder="Digite sua cidade"
                    className="bg-white rounded-xl w-full"
                  />
                </div>
                <div className="flex mb-4 mx-4">
                  {/* <TextField
                    variant="outlined"
                    id="outlined-basic"
                    label="Estado"
                    placeholder="Digite a sigla do estado"
                    className="bg-white rounded-xl w-full"
                  /> */}
                  <InputMask
                    mask=""
                    placeholder="Digite a sigla do estado"
                    value={Estado}
                    onChange={(e) => setEstado(e.target.value)}
                  >
                    <TextField
                      className="bg-white rounded-xl w-full"
                      id="outlined-basic"
                      label="Estado"
                      variant="outlined"
                    />
                  </InputMask>
                </div>
              </div>
            </div>

            <div className="col">
              <Typography variant="h3" className="title">
                Pagamento
              </Typography>

              <div className="flex flex-col lg:flex-row justify-around">
                <div className="flex flex-col lg:flex-row mx-4">
                  <Button
                    size="large"
                    variant="contained"
                    className="flex rounded-xl bg-purple text-white my-4 hover:bg-purple"
                  >
                    Pix
                  </Button>
                </div>
                <div className="flex flex-col lg:flex-row mx-4">
                  <Button
                    size="large"
                    variant="contained"
                    className="flex flex-col lg:flex-row rounded-xl bg-purple text-white my-4 hover:bg-purple"
                  >
                    Cartão de crédito
                  </Button>
                </div>
                <div className="flex flex-col lg:flex-row mx-4">
                  <Button
                    size="large"
                    variant="contained"
                    className="flex flex-col lg:flex-row rounded-xl bg-purple text-white my-4 hover:bg-purple"
                  >
                    Boleto
                  </Button>
                </div>
              </div>
              <div className="flex flex-col lg:flex-row mb-4 mx-4">
                <TextField
                  variant="outlined"
                  id="outlined-basic"
                  label="Nome do cartão"
                  placeholder="Digite o nome do cartão"
                  className="bg-white rounded-xl w-full"
                />
              </div>
              <div className="flex flex-col lg:flex-row mb-4 mx-4">
                <TextField
                  type="number"
                  variant="outlined"
                  id="outlined-basic"
                  label="Número do cartão"
                  placeholder="Digite o número do cartão"
                  className="bg-white rounded-xl w-full"
                />
              </div>
              <div className="flex flex-col lg:flex-row mb-4 mx-4">
                <Typography variant="body1">Data de validade</Typography>
                <TextField
                  type="month"
                  variant="outlined"
                  id="outlined-basic"
                  // label="Data de validade"
                  placeholder="DD-MM-AAAA"
                  className="bg-white rounded-xl w-full"
                />
                {/* <InputMask
                  mask="99-99-9999"
                  placeholder="DD-MM-AAAA"
                  value={Data}
                  onChange={(e) => setData(e.target.value)}
                  >
                  <TextField
                    type="month"
                    className="bg-white rounded-xl w-full"
                    id="outlined-basic"
                    label="Data de validade (DD-MM-AAAA)"
                    variant="outlined"
                  />
                </InputMask> */}
              </div>

              <div className="flex flex-col lg:flex-row">
                <div className="flex flex-col lg:flex-row mb-4 mx-4">
                  {/* <TextField
                    type="number"
                    variant="outlined"
                    id="outlined-basic"
                    label="CVV"
                    placeholder="Digite o número CVV do cartão"
                    helperText="Número de 3 dígitos na parte de trás do seu cartão"
                    className="bg-white rounded-xl w-full"
                  /> */}
                  <InputMask
                    mask="999"
                    placeholder="Digite o CVV do cartão"
                    value={CVV}
                    onChange={(e) => setCVV(e.target.value)}
                  >
                    <TextField
                      className="bg-white rounded-xl w-full"
                      id="outlined-basic"
                      label="CVV"
                      variant="outlined"
                      helperText="Número de 3 dígitos na parte de trás do seu cartão"
                    />
                  </InputMask>
                </div>
              </div>
              <div className="flex flex-col lg:flex-row justify-center">
                <Link href="/waitingPayment">
                  <Button
                    size="large"
                    variant="contained"
                    className="flex rounded-xl bg-purple text-white my-4 hover:bg-purple"
                  >
                    Confirmar compra
                  </Button>
                </Link>
              </div>
            </div>
          </div>
        </form>
      </div>
      <Footer />
    </>
  );
};

export default Checkout;
