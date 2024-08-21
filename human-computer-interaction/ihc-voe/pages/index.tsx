import { Button, TextField, Typography } from '@mui/material';
import type { NextPage } from 'next';
import Head from 'next/head';
import Image from 'next/image';
import Footer from '../components/footer';
import Header from '../components/header';
import MainSearch from '../components/mainSearch';
import China from '../public/china.png';
import Carousel from '../public/carousel.png';
import Recife from '../public/recife.png';

const Home: NextPage = () => {
  return (
    <div className="flex min-h-screen flex-col">
      <Head>
        <title>Voe</title>
        <link rel="icon" href="/logo.ico" />
      </Head>

      <Header />

      <main>
        <MainSearch />
        <div className="flex flex-col items-center justify-center mx-8">
          <Image
            className="my-8"
            src={Carousel}
            width={1300}
            height={500}
            title="Imagem paisagem"
            alt="Imagem paisagem"
          />
          <div className="flex flex-col">
            <div className="flex flex-col items-center">
              <Typography variant="h5" className="my-4 text-purple">
                Destinos em alta
              </Typography>
              <div className="flex flex-col lg:flex-row justify-around">
                <div className="flex flex-col border border-black border-solid rounded-xl items-center justify-around m-4 p-4">
                  <Image
                    src={China}
                    width={500}
                    height={200}
                    alt="Imagem viagem"
                    title="Imagem viagem"
                  />
                  <div className="flex flex-col lg:flex-row items-center justify-around w-full">
                    <Typography variant="body1">Pacotes a partir de 10x de R$229</Typography>
                    <Button
                      variant="contained"
                      className="flex rounded-xl bg-white text-purple my-4"
                    >
                      Ver agora
                    </Button>
                  </div>
                </div>
                <div className="flex flex-col border border-black border-solid rounded-xl items-center justify-around m-4 p-4">
                  <Image
                    src={Recife}
                    width={500}
                    height={200}
                    alt="Imagem viagem"
                    title="Imagem viagem"
                  />
                  <div className="flex flex-col lg:flex-row items-center justify-around w-full">
                    <Typography variant="body1">Pacotes a partir de 10x de R$229</Typography>
                    <Button
                      variant="contained"
                      className="flex rounded-xl bg-white text-purple my-4"
                    >
                      Ver agora
                    </Button>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <div className="flex flex-col lg:flex-row bg-purple my-8 p-4 items-center justify-center w-full border rounded-xl">
            <Typography variant="h6" className="text-white py-4 lg:px-4">
              Cadastre-se agora e recebe ofertas e muito mais!
            </Typography>
            <TextField label="Insira seu email" className="bg-white rounded-xl w-1/2" />
            <Button
              variant="contained"
              className="flex rounded-xl bg-white text-purple my-4 mx-4 lg:px-4"
            >
              Cadastrar
            </Button>
          </div>
        </div>
      </main>

      <Footer />
    </div>
  );
};

export default Home;
