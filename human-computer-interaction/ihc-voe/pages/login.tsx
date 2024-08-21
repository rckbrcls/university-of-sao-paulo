import { ReactNode, useState } from 'react';
import { Facebook, Google } from '@mui/icons-material';
import {
  Button,
  Checkbox,
  FormControlLabel,
  FormGroup,
  TextField,
  Typography,
} from '@mui/material';
import type { NextPage } from 'next';
import Footer from '../components/footer';
import Header from '../components/header';
import InputMask from 'react-input-mask';

const Login: NextPage = () => {
  const [CEP, setCEP] = useState('');
  const [CPF, setCPF] = useState('');

  return (
    <>
      <Header />
      <div className="flex flex-row justify-center m-8 p-4">
        <form method="post" className="pr-4 border-r border-solid border-black">
          <Typography variant="h4">Entrar</Typography>
          <div className="grid grid-cols-2 gap-4">
            <div className="flex flex-col">
              <TextField
                className="bg-white rounded-xl mt-4"
                id="outlined-basic"
                label="E-mail"
                placeholder="exemplo@email.com"
                variant="outlined"
                required
                type="email"
              />
              <TextField
                className="bg-white rounded-xl mt-4"
                id="outlined-basic"
                label="Senha"
                placeholder="Senha"
                variant="outlined"
                type="password"
                required
              />
            </div>
            <div className="flex flex-col justify-center">
              <Button variant="outlined" startIcon={<Facebook />} size="large" className="mb-4">
                Entrar com Facebook
              </Button>
              <Button variant="outlined" startIcon={<Google />} size="large">
                Entrar com Google
              </Button>
            </div>
          </div>
          <FormGroup>
            <FormControlLabel control={<Checkbox />} label="Manter-me conectado" />
          </FormGroup>
          <Button variant="text" className="flex items-start">
            Esqueci minha senha
          </Button>
          <Button
            size="large"
            variant="contained"
            className="flex rounded-xl bg-purple text-white my-4 hover:bg-purple"
          >
            Entrar
          </Button>
        </form>

        <form method="post" className="ml-4">
          <Typography variant="h4">Crie sua conta</Typography>
          <div className="grid grid-cols-2 gap-4">
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="Nome completo"
              placeholder="Nome completo"
              variant="outlined"
              required
            />
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="E-mail"
              placeholder="exemplo@email.com"
              variant="outlined"
              required
              type="email"
            />
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="Senha"
              placeholder="Senha"
              variant="outlined"
              type="password"
              required
            />
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="Confirmar senha"
              placeholder="Confirmar senha"
              variant="outlined"
              type="password"
              required
            />
            <InputMask
              mask="999.999.999-99"
              placeholder="Digite o seu CPF"
              value={CPF}
              onChange={(e) => setCPF(e.target.value)}
            >
              <TextField
                className="bg-white rounded-xl mt-4"
                id="outlined-basic"
                label="CPF"
                variant="outlined"
                required
              />
            </InputMask>

            <InputMask
              mask="99 999-999"
              placeholder="Digite o seu CEP"
              value={CEP}
              onChange={(e) => setCEP(e.target.value)}
            >
              <TextField
                className="bg-white rounded-xl mt-4"
                id="outlined-basic"
                label="CEP"
                variant="outlined"
                required
              />
            </InputMask>
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="Endereço"
              placeholder="Digite o nome da rua"
              variant="outlined"
              required
            />
            <TextField
              className="bg-white rounded-xl mt-4"
              id="outlined-basic"
              label="Número residência"
              placeholder="Digite o número da residência"
              variant="outlined"
              required
              type="number"
            />
          </div>
          <Button
            size="large"
            variant="contained"
            className="flex rounded-xl bg-purple text-white my-4 hover:bg-purple"
          >
            Cadastrar
          </Button>
        </form>
      </div>

      <Footer />
    </>
  );
};

export default Login;
