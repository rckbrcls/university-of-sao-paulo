import '../styles/globals.css';
import type { AppProps } from 'next/app';
import '@fontsource/roboto/300.css';
import '@fontsource/roboto/400.css';
import '@fontsource/roboto/500.css';
import '@fontsource/roboto/700.css';
import '../styles/checkout.css';
import VLibras from 'vlibras-nextjs';

function MyApp({ Component, pageProps }: AppProps) {
  return (
    <>
      <Component {...pageProps} />
      <VLibras forceOnload />
    </>
  );
}

export default MyApp;
