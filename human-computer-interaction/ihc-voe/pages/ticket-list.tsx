import type { NextPage } from "next";
import Head from "next/head";
import Footer from "../components/footer";
import Header from "../components/header";
import MainSearch from "../components/mainSearch";
import TicketCard from "../components/ticketCard";

const TicketList: NextPage = () => {
  return (
    <div className="flex min-h-screen flex-col">
      <Head>
        <title>Voe</title>
        <link rel="icon" href="/logo.ico" />
      </Head>
      <Header />
      <main>
        <MainSearch />
        <TicketCard />
        <TicketCard />
        <TicketCard />
        <TicketCard />
        <TicketCard />
      </main>
      <Footer />
    </div>
  );
};

export default TicketList;
