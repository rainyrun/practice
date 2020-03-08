-- MySQL dump 10.13  Distrib 8.0.17, for macos10.14 (x86_64)
--
-- Host: localhost    Database: demostumanager
-- ------------------------------------------------------
-- Server version	8.0.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `sname` varchar(20) DEFAULT NULL,
  `sex` varchar(10) DEFAULT NULL,
  `phone` varchar(20) DEFAULT NULL,
  `hobby` varchar(50) DEFAULT NULL,
  `descript` varchar(100) DEFAULT NULL,
  `create_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB AUTO_INCREMENT=34 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'彼得','男','15123456789','读书, 爬山','是一个静若处子动若脱兔的男孩子','2019-07-25 10:05:50'),(4,'宋雨绮','女','13537674567','游泳, 读书','像泰迪一样可爱','2019-07-26 02:45:51'),(17,'王大陆','男','15234343434','游泳, 爬山, 跑步','国民初恋','2019-07-26 07:51:43'),(18,'赵惠珍','女','15273854646','读书','超会扭的赵女士','2019-07-26 12:35:12'),(19,'田小娟','女','15284767777','游泳, 跑步','可盐可甜的ace','2019-07-26 12:35:44'),(20,'王嘉尔','男','16328384444','游泳, 跑步','国际嘎','2019-07-26 12:36:09'),(21,'叶舒华','女','15237466666','读书, 爬山','冷面女生门面担当','2019-07-26 12:36:52'),(22,'宋闵浩','男','15322227777','游泳, 爬山, 跑步','宋村傻，综艺天才','2019-07-26 12:37:49'),(23,'金秦禹','男','15322338564','游泳, 爬山, 跑步','绝世美颜，大眼清澈如小鹿','2019-07-26 12:39:07'),(24,'宋慧乔','女','15274759474','游泳','代表作《浪漫满屋》','2019-07-28 08:56:28'),(25,'李晟基','男','15237456666','游泳, 读书, 爬山, 跑步','家师傅一体，两天一夜','2019-07-28 09:05:16'),(26,'金煎妮','女','16434343435','游泳, 跑步','舞台风格强烈','2019-07-28 09:06:28'),(27,'金智秀','女','17363636363','读书','人间四月天','2019-07-28 09:07:08'),(29,'大宝贝金','女','15235353535','读书','全靠颜值','2019-07-29 07:55:28'),(30,'水冰月','女','15234343434','读书,爬山,跑步','超级无敌美少女','2019-08-28 03:00:00'),(31,'夜礼服假面金','男','15624563846','游泳,爬山,跑步','只在夜晚出现的神秘男子','2019-08-28 14:43:51'),(33,'大宝天天见','男','13537674567','游泳,读书','大宝天天见','2019-08-28 19:23:09');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `uid` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) DEFAULT NULL,
  `password` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'root','admin'),(3,'abc','efg'),(4,'rainy','rainy');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-03-05 16:39:02
