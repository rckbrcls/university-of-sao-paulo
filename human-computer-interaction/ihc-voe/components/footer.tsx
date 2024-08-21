import { Pix, CreditCard, AttachMoney } from '@mui/icons-material';
import { Typography, Button } from '@mui/material';
import Image from 'next/image';
import Logo_white from '../public/logo.svg';

export default function Footer() {
  return (
    <footer className="flex flex-col w-full items-center justify-center border-t bg-purple mt-auto">
      <div className="flex flex-col items-center">
        <div className="flex flex-row my-8">
          <Image alt="Voe logo" src={Logo_white} />
          <div className="mx-4 text-white">
            <Typography variant="h6">Voe Viagens e Turismo LTDA.</Typography>
            <Typography variant="body1">
              CNPJ 26.669.170/0001-57 <br />
              Rua Guaíra 38 - Queimados <br />
              CEP 30.130-140, Rio de Janeiro/RJ <br />
            </Typography>
          </div>
        </div>
        <div className="flex flex-col lg:flex-row flex-row">
          <Button className="text-white" color="primary" variant="text">
            Quem somos
          </Button>
          <Button className="text-white" color="primary" variant="text">
            Blog
          </Button>
          <Button className="text-white" color="primary" variant="text">
            Política de privacidade
          </Button>
          <Button className="text-white" color="primary" variant="text">
            Termos e condições
          </Button>
          <Button className="text-white" color="primary" variant="text">
            Carreiras
          </Button>
          <Button className="text-white" color="primary" variant="text">
            Acessibilidade
          </Button>
        </div>
        <div className="flex flex-col items-center text-white my-4">
          <Typography variant="h5">Formas de pagamento</Typography>
          <Typography variant="body1">
            Pague no cartão de crédito em até 12X com juros, boleto à vista ou parcelado,
            transferência bancária ou com pix!
          </Typography>
          <div className="flex flex-row my-4">
            <Pix />
            <CreditCard />
            <AttachMoney />
          </div>
        </div>
      </div>
    </footer>
  );
}
