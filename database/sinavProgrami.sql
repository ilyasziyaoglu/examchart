CREATE DATABASE  IF NOT EXISTS `sinavProgrami` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `sinavProgrami`;
-- MySQL dump 10.13  Distrib 5.7.24, for Linux (x86_64)
--
-- Host: localhost    Database: sinavProgrami
-- ------------------------------------------------------
-- Server version	5.7.24-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Dumping data for table `bolumler`
--

LOCK TABLES `bolumler` WRITE;
/*!40000 ALTER TABLE `bolumler` DISABLE KEYS */;
INSERT INTO `bolumler` VALUES (3,6,'bilgisayar','blm201'),(4,6,'elektrik','elk200'),(5,6,'makine','mkn200'),(6,7,'iktisat','ikt100'),(7,6,'isletme','isl100'),(8,7,'kamuyonetimi','kmy'),(9,10,'grafik tasarim','gft');
/*!40000 ALTER TABLE `bolumler` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `ders_salon`
--

LOCK TABLES `ders_salon` WRITE;
/*!40000 ALTER TABLE `ders_salon` DISABLE KEYS */;
INSERT INTO `ders_salon` VALUES (1,1,1,'11:00','carsamba'),(2,2,3,'14:00','cuma'),(3,3,9,'09:00','sali'),(4,4,1,'09:00','carsamba');
/*!40000 ALTER TABLE `ders_salon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `dersler`
--

LOCK TABLES `dersler` WRITE;
/*!40000 ALTER TABLE `dersler` DISABLE KEYS */;
INSERT INTO `dersler` VALUES (1,'ders1',3,'dagitiksistemler',7,60,1,50),(2,'ders2',3,'ypy',7,60,2,50),(3,'ders3',4,'aydinlatma',3,60,7,40),(4,'ders4',9,'temel cizim',1,60,8,60);
/*!40000 ALTER TABLE `dersler` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `fakulteler`
--

LOCK TABLES `fakulteler` WRITE;
/*!40000 ALTER TABLE `fakulteler` DISABLE KEYS */;
INSERT INTO `fakulteler` VALUES (6,38,'mühendislik','fakkod1'),(7,38,'iibf','fakkod2'),(8,38,'hukuk','fakkod3'),(9,39,'mimarlik','fakkod4'),(10,39,'güzelsanatlar','fakkod5'),(11,40,'denizcilik','fakkod6');
/*!40000 ALTER TABLE `fakulteler` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `kampusler`
--

LOCK TABLES `kampusler` WRITE;
/*!40000 ALTER TABLE `kampusler` DISABLE KEYS */;
INSERT INTO `kampusler` VALUES (39,'anitpark'),(40,'karamürsel'),(41,'kartepe'),(42,'merhaba'),(38,'umuttepe');
/*!40000 ALTER TABLE `kampusler` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `personeller`
--

LOCK TABLES `personeller` WRITE;
/*!40000 ALTER TABLE `personeller` DISABLE KEYS */;
INSERT INTO `personeller` VALUES (1,'100',3,'ahmet sayar','prof'),(2,'101',3,'orhan akbulut','doç'),(3,'102',3,'süleyman eken','ar gor'),(4,'103',3,'furkan goz','ar gor'),(5,'104',4,'nureddin abut','prof'),(7,'105',4,'ali bekir','prof'),(8,'106',9,'tofig rustemov','prof');
/*!40000 ALTER TABLE `personeller` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `salonlar`
--

LOCK TABLES `salonlar` WRITE;
/*!40000 ALTER TABLE `salonlar` DISABLE KEYS */;
INSERT INTO `salonlar` VALUES (1,'301',3,'sinif1',30),(2,'305',3,'sinif2',40),(3,'303',3,'sinif3',50),(4,'307',3,'Amfi A',70),(5,'309',3,'Amfi B',90),(6,'311',3,'Büyük Amfi',150),(7,'201',4,'sinif1',50),(8,'203',4,'sinif2',60),(9,'205',4,'Amfi A',90),(10,'102',9,'sinif1',60);
/*!40000 ALTER TABLE `salonlar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `sinavlar`
--

LOCK TABLES `sinavlar` WRITE;
/*!40000 ALTER TABLE `sinavlar` DISABLE KEYS */;
INSERT INTO `sinavlar` VALUES (1,1,50,1,'2019-01-14','13:00',1),(2,2,55,2,'2019-01-14','15:00',2),(3,3,70,9,'2000-01-12','10:00',7),(5,1,0,NULL,NULL,NULL,NULL),(6,4,10,10,'2019-01-13','12:00',8);
/*!40000 ALTER TABLE `sinavlar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES ('em','emil mammadov','123',2,3),('im','ilyas mammadov','123',1,3),('selda','selda tas','123',2,7);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-01-12 15:30:39
