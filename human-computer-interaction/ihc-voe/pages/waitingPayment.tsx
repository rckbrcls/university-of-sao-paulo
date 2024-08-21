import { Button, Typography } from '@mui/material';
import type { NextPage } from 'next';
import Link from 'next/link';
import Footer from '../components/footer';
import Header from '../components/header';

const WaitingPayment: NextPage = () => {
  return (
    <>
      <Header />
      <div className="flex flex-col justify-center items-center bg-purple border rounded-xl m-8 p-4">
        <div className="flex flex-col items-center">
          <Typography variant="h4" className="text-white my-4">
            Pagamento em análise!
          </Typography>
          <Typography variant="h5" className="text-white">
            Você receberá uma confirmação no seu e-mail cadastrado.
            <br />
            Aproveite sua viagem!
          </Typography>
        </div>
        <div>
          <Button className="flex justify-center items-center border rounded-xl bg-gray-dark m-4 p-4">
            <Typography variant="button" className="text-white">
              Minhas passagens
            </Typography>
          </Button>
        </div>
        <div>
          <Link href="/">
            <Button className="flex justify-center items-center border rounded-xl bg-gray-dark m-4 p-4">
              <Typography variant="button" className="text-white">
                Home
              </Typography>
            </Button>
          </Link>
        </div>
      </div>

      <Footer />
    </>
  );
};

export default WaitingPayment;
