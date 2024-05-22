-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: mysql-dev:3306
-- Creato il: Mag 22, 2024 alle 13:51
-- Versione del server: 8.4.0
-- Versione PHP: 8.2.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `settimaEsercitazione`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `artisti`
--

CREATE TABLE `artisti` (
  `id` int NOT NULL,
  `nome` text NOT NULL,
  `cognome` text NOT NULL,
  `nomeArte` text,
  `biografia` text,
  `casaDiscograficaId` int NOT NULL,
  `dataInserimento` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `artisti_canzoni`
--

CREATE TABLE `artisti_canzoni` (
  `id` int NOT NULL,
  `idArtista` int NOT NULL,
  `idCanzone` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `canzoni`
--

CREATE TABLE `canzoni` (
  `id` int NOT NULL,
  `nome` text NOT NULL,
  `durataMinuti` int NOT NULL,
  `casaDiscograficaId` int NOT NULL,
  `dataPubblicazione` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Struttura della tabella `caseDiscografiche`
--

CREATE TABLE `caseDiscografiche` (
  `id` int NOT NULL,
  `nome` text NOT NULL,
  `website` int DEFAULT NULL,
  `dataFondazione` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `artisti`
--
ALTER TABLE `artisti`
  ADD PRIMARY KEY (`id`),
  ADD KEY `casaDiscograficaId` (`casaDiscograficaId`);

--
-- Indici per le tabelle `artisti_canzoni`
--
ALTER TABLE `artisti_canzoni`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idArtista` (`idArtista`),
  ADD KEY `idCanzone` (`idCanzone`);

--
-- Indici per le tabelle `canzoni`
--
ALTER TABLE `canzoni`
  ADD PRIMARY KEY (`id`),
  ADD KEY `casaDiscograficaId` (`casaDiscograficaId`);

--
-- Indici per le tabelle `caseDiscografiche`
--
ALTER TABLE `caseDiscografiche`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `artisti`
--
ALTER TABLE `artisti`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `artisti_canzoni`
--
ALTER TABLE `artisti_canzoni`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `canzoni`
--
ALTER TABLE `canzoni`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT per la tabella `caseDiscografiche`
--
ALTER TABLE `caseDiscografiche`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- Limiti per le tabelle scaricate
--

--
-- Limiti per la tabella `artisti`
--
ALTER TABLE `artisti`
  ADD CONSTRAINT `artisti_ibfk_1` FOREIGN KEY (`casaDiscograficaId`) REFERENCES `caseDiscografiche` (`id`);

--
-- Limiti per la tabella `artisti_canzoni`
--
ALTER TABLE `artisti_canzoni`
  ADD CONSTRAINT `artisti_canzoni_ibfk_1` FOREIGN KEY (`idArtista`) REFERENCES `artisti` (`id`),
  ADD CONSTRAINT `artisti_canzoni_ibfk_2` FOREIGN KEY (`idCanzone`) REFERENCES `canzoni` (`id`);

--
-- Limiti per la tabella `canzoni`
--
ALTER TABLE `canzoni`
  ADD CONSTRAINT `canzoni_ibfk_1` FOREIGN KEY (`casaDiscograficaId`) REFERENCES `caseDiscografiche` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
