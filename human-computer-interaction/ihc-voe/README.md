# Voe

> Status: archived HCI coursework prototype.

Voe is a travel-booking interface prototype built for a human-computer interaction course. The project focuses on UI screens, form flows, visual structure, and accessibility-oriented dependencies. It should be treated as a frontend prototype, not as a production booking system.

## Scope

- Project type: single Next.js frontend app.
- Main stack: Next.js, React 18, TypeScript, Material UI, Emotion, Tailwind CSS, React Input Mask, Roboto font source, and VLibras.
- Package manager: Yarn, based on `yarn.lock`.
- Backend: none identified.
- Authentication: UI-only login/signup screens; no real auth backend was identified.
- Payments: UI-only checkout flow; no real payment processor was identified.

## Main Screens

| Path | Responsibility |
| --- | --- |
| `pages/index.tsx` | Home page with header, search flow, featured destinations, and newsletter form. |
| `pages/login.tsx` | Login and account-creation interface with email, password, CPF, and CEP inputs. |
| `pages/ticket-list.tsx` | Ticket-list screen that renders available ticket cards. |
| `pages/checkout.tsx` | Passenger and payment-form UI for the checkout flow. |
| `pages/waitingPayment.tsx` | Waiting-payment confirmation screen. |
| `pages/_app.tsx` | Global app wrapper and VLibras integration. |

## Components

| Path | Responsibility |
| --- | --- |
| `components/header.tsx` | Shared navigation/header. |
| `components/footer.tsx` | Shared footer. |
| `components/mainSearch.tsx` | Main search form and route into the ticket list. |
| `components/ticketCard.tsx` | Ticket card UI and link into checkout. |
| `components/resumeCard.tsx` | Checkout summary card. |

## Setup

The original README referenced Node.js greater than version 14 and Yarn. The exact supported Node.js range was not identified in the current codebase.

```sh
cd human-computer-interaction/ihc-voe
yarn
```

## Available Scripts

The scripts come from `package.json`.

| Command | Purpose |
| --- | --- |
| `yarn dev` | Starts the Next.js development server. |
| `yarn build` | Creates a production Next.js build. |
| `yarn start` | Starts the production Next.js server after a build. |

## Styling and Assets

- `styles/globals.css` contains global styles and Tailwind imports.
- `styles/checkout.css` contains checkout-specific layout styles.
- `tailwind.config.js` configures Tailwind.
- `public/` stores logos and travel images used by the prototype.

## Accessibility Notes

`pages/_app.tsx` imports and renders `VLibras` from `vlibras-nextjs`, which indicates an accessibility-oriented requirement for Brazilian Sign Language support. Input masks are used for fields such as CPF, CEP, and CVV.

## Limitations

- The visible interface text in the source is mostly Portuguese because this is a historical coursework prototype.
- Login, signup, ticket search, checkout, and payment screens do not connect to a real backend in the current codebase.
- No tests were identified.
- No deployment configuration was identified beyond the default Next.js scripts.
