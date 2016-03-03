/*
 Navicat Premium Data Transfer

 Source Server         : CheckItNow
 Source Server Type    : MySQL
 Source Server Version : 50545
 Source Host           : localhost
 Source Database       : BookShop

 Target Server Type    : MySQL
 Target Server Version : 50545
 File Encoding         : utf-8

 Date: 11/28/2015 19:29:58 PM
*/

SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
--  Table structure for `Administer`
-- ----------------------------
DROP TABLE IF EXISTS `Administer`;
CREATE TABLE `Administer` (
  `UserName` varchar(20) NOT NULL,
  `Password` varchar(20) NOT NULL,
  PRIMARY KEY (`UserName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `Administer`
-- ----------------------------
BEGIN;
INSERT INTO `Administer` VALUES ('Ace', 'allkill'), ('Mark', 'mroot');
COMMIT;

-- ----------------------------
--  Table structure for `Book`
-- ----------------------------
DROP TABLE IF EXISTS `Book`;
CREATE TABLE `Book` (
  `ISBN` char(17) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Author` varchar(30) DEFAULT NULL,
  `Press` varchar(40) DEFAULT NULL,
  `PublishDate` date DEFAULT NULL,
  `Price` float NOT NULL,
  `isDiscount` tinyint(1) DEFAULT NULL,
  `Storage` int(10) unsigned zerofill NOT NULL,
  `hasCover` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`ISBN`),
  KEY `ISBN` (`ISBN`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `Book`
-- ----------------------------
BEGIN;
INSERT INTO `Book` VALUES ('978-7-2080-6164-4', '追风筝的人', '[美]卡勒德•胡赛尼', '上海人民出版社', '2006-05-01', '29.8', '1', '15', '1'), ('978-7-3070-7542-9', '天才在左 疯子在右', '高铭', '武汉大学出版社', '2010-02-01', '29.8', '1', '25', '1'), ('978-7-5086-2833-2', '别相信任何人', '[英]S.J.沃森', '中信出版社', '2011-10-01', '29', '1', '20', '1'), ('978-7-5327-5154-9', '机场里的小旅行', '[英]阿兰·德波顿', '上海译文出版社', '2010-08-01', '25', '1', '30', '1'), ('978-7-5354-3980-2', '西决', '笛安', '长江文艺出版社', '2009-03-01', '22.8', '1', '35', '1'), ('978-7-5354-7689-0', '狼图腾(修订版)', '姜戎', '长江文艺出版社', '2014-12-01', '39.8', '0', '27', '1'), ('978-7-5399-7181-0', '岛上书店', '[美]加布瑞埃拉·泽文', '江苏凤凰文艺出版社', '2015-05-01', '35', '0', '31', '1'), ('978-7-5399-8283-0', '无声告白', '[美]伍绮诗', '江苏凤凰文艺出版社', '2015-07-01', '35', '0', '29', '1'), ('978-7-5426-3166-4', '送你一颗子弹', '刘瑜', '上海三联书店', '2010-01-01', '25', '1', '20', '1'), ('978-7-5442-6841-7', '没有色彩的多崎作和他的巡礼之年', '[日]村上春树', '南海出版社', '2013-10-01', '39.5', '1', '35', '1'), ('978-7-5442-7087-8', '解忧杂货店', '[日]东野圭吾', '南海出版社', '2014-05-01', '39.5', '0', '12', '1'), ('978-7-5447-1688-8', '奇风岁月', '[美]罗伯特·麦卡蒙', '译林出版社', '2011-06-01', '36', '1', '37', '1');
COMMIT;

-- ----------------------------
--  Table structure for `Discount`
-- ----------------------------
DROP TABLE IF EXISTS `Discount`;
CREATE TABLE `Discount` (
  `Level` smallint(6) NOT NULL,
  `Discount` float NOT NULL,
  PRIMARY KEY (`Level`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `Discount`
-- ----------------------------
BEGIN;
INSERT INTO `Discount` VALUES ('1', '0.9'), ('2', '0.85'), ('3', '0.8'), ('4', '0.75'), ('5', '0.7');
COMMIT;

-- ----------------------------
--  Table structure for `Replenish`
-- ----------------------------
DROP TABLE IF EXISTS `Replenish`;
CREATE TABLE `Replenish` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `BookISBN` char(17) NOT NULL,
  `Number` int(11) DEFAULT NULL,
  `Time` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `BookISBN` (`BookISBN`),
  CONSTRAINT `key` FOREIGN KEY (`BookISBN`) REFERENCES `Book` (`ISBN`) ON DELETE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `Replenish`
-- ----------------------------
BEGIN;
INSERT INTO `Replenish` VALUES ('1', '978-7-5442-7087-8', '20', '2014-12-01'), ('2', '978-7-5399-7181-0', '30', '2014-12-15'), ('3', '978-7-5442-6841-7', '20', '2015-10-01'), ('4', '978-7-5354-7689-0', '10', '2015-10-15'), ('5', '978-7-3070-7542-9', '30', '2015-11-01'), ('6', '978-7-2080-6164-4', '50', '2015-11-03'), ('7', '978-7-5354-3980-2', '30', '2015-11-04'), ('8', '978-7-5399-8283-0', '10', '2015-11-05'), ('9', '978-7-5354-7689-0', '10', '2015-11-05'), ('10', '978-7-5447-1688-8', '10', '2015-11-06'), ('11', '978-7-5354-3980-2', '10', '2015-11-06'), ('12', '978-7-2080-6164-4', '10', '2015-11-10'), ('13', '978-7-5442-6841-7', '10', '2015-11-10'), ('14', '978-7-5447-1688-8', '10', '2015-11-26'), ('15', '978-7-5327-5154-9', '30', '2015-11-26');
COMMIT;

-- ----------------------------
--  Table structure for `Sell`
-- ----------------------------
DROP TABLE IF EXISTS `Sell`;
CREATE TABLE `Sell` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `vipID` int(11) DEFAULT NULL,
  `BookISBN` char(17) NOT NULL,
  `Number` int(11) NOT NULL,
  `Discount` float DEFAULT NULL,
  `Sum` decimal(10,1) NOT NULL,
  `Time` date NOT NULL,
  PRIMARY KEY (`id`),
  KEY `BookISBN` (`BookISBN`),
  KEY `vipID` (`vipID`),
  CONSTRAINT `key_ISBN` FOREIGN KEY (`BookISBN`) REFERENCES `Book` (`ISBN`) ON DELETE NO ACTION,
  CONSTRAINT `key_vip` FOREIGN KEY (`vipID`) REFERENCES `VIP` (`id`) ON DELETE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `Sell`
-- ----------------------------
BEGIN;
INSERT INTO `Sell` VALUES ('1', null, '978-7-5399-7181-0', '3', '1', '105.0', '2014-11-10'), ('2', '2', '978-7-5399-7181-0', '2', '0.9', '63.0', '2014-12-01'), ('3', null, '978-7-5399-7181-0', '1', '1', '35.0', '2014-12-01'), ('4', '1', '978-7-5442-6841-7', '3', '0.85', '100.7', '2015-09-01'), ('5', '1', '978-7-5442-7087-8', '2', '0.85', '67.2', '2015-09-02'), ('6', '1', '978-7-5442-6841-7', '2', '0.85', '67.2', '2015-09-02'), ('7', '1', '978-7-5442-7087-8', '1', '0.85', '33.6', '2015-09-12'), ('8', '4', '978-7-5399-7181-0', '3', '0.85', '89.2', '2015-09-12'), ('9', '4', '978-7-5442-7087-8', '8', '0.85', '268.6', '2015-10-01'), ('10', null, '978-7-2080-6164-4', '2', '1', '59.6', '2015-10-05'), ('11', '1', '978-7-2080-6164-4', '2', '0.75', '44.7', '2015-10-05'), ('12', '1', '978-7-3070-7542-9', '2', '0.75', '44.7', '2015-10-15'), ('13', '3', '978-7-3070-7542-9', '2', '0.9', '53.6', '2015-10-15'), ('14', null, '978-7-3070-7542-9', '1', '1', '29.8', '2015-11-01'), ('15', null, '978-7-5354-3980-2', '1', '1', '22.8', '2015-11-01'), ('16', null, '978-7-5399-8283-0', '1', '1', '35.0', '2015-11-02'), ('17', null, '978-7-5442-6841-7', '1', '1', '39.5', '2015-11-02'), ('18', null, '978-7-5447-1688-8', '1', '1', '36.0', '2015-11-02'), ('19', null, '978-7-5442-7087-8', '10', '1', '395.0', '2015-11-03'), ('20', '2', '978-7-5447-1688-8', '2', '0.85', '61.2', '2015-11-04'), ('21', '5', '978-7-5442-6841-7', '2', '0.85', '67.2', '2015-11-04'), ('22', '5', '978-7-5399-7181-0', '2', '1', '70.0', '2015-11-05'), ('23', '3', '978-7-5354-7689-0', '3', '1', '119.4', '2015-11-05'), ('24', '3', '978-7-5354-3980-2', '1', '0.9', '20.5', '2015-11-06'), ('25', '2', '978-7-5354-3980-2', '1', '0.85', '19.4', '2015-11-06'), ('26', null, '978-7-5354-3980-2', '1', '1', '22.8', '2015-11-06'), ('27', null, '978-7-5354-7689-0', '1', '1', '39.8', '2015-11-06'), ('28', null, '978-7-2080-6164-4', '2', '1', '59.6', '2015-11-07'), ('29', '1', '978-7-2080-6164-4', '2', '0.75', '44.7', '2015-11-07'), ('30', '3', '978-7-2080-6164-4', '2', '0.9', '53.6', '2015-11-07'), ('31', null, '978-7-2080-6164-4', '1', '1', '29.8', '2015-11-26'), ('32', '1', '978-7-2080-6164-4', '1', '0.75', '22.3', '2015-11-26'), ('33', '4', '978-7-2080-6164-4', '1', '0.8', '23.8', '2015-11-26'), ('34', '4', '978-7-5354-7689-0', '1', '1', '39.8', '2015-11-26'), ('35', '1', '978-7-5354-7689-0', '1', '1', '39.8', '2015-11-26');
COMMIT;

-- ----------------------------
--  Table structure for `VIP`
-- ----------------------------
DROP TABLE IF EXISTS `VIP`;
CREATE TABLE `VIP` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(20) NOT NULL,
  `Sex` char(4) DEFAULT NULL,
  `Birthday` date DEFAULT NULL,
  `Telephone` varchar(11) DEFAULT NULL,
  `Email` varchar(30) DEFAULT NULL,
  `Score` smallint(6) NOT NULL,
  `Level` smallint(6) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `Level` (`Level`),
  CONSTRAINT `key_level` FOREIGN KEY (`Level`) REFERENCES `Discount` (`Level`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
--  Records of `VIP`
-- ----------------------------
BEGIN;
INSERT INTO `VIP` VALUES ('1', '丁丁', '男', '1995-01-01', '18800002814', 'dingding@txbb.com', '65', '4'), ('2', '迪西', '男', '1995-09-25', '13700009423', 'dixi@txbb.com', '35', '2'), ('3', '拉拉', '女', '1996-06-11', '13600003825', 'lala@txbb.com', '90', '1'), ('4', '波', '女', '1998-02-07', '18200002718', 'imbo@txbb.com', '60', '3'), ('5', '张三', '男', '1991-01-05', '13902341731', 'zhangsan@someone.com', '45', '2');
COMMIT;

-- ----------------------------
--  View structure for `daily_revenue`
-- ----------------------------
DROP VIEW IF EXISTS `daily_revenue`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `daily_revenue` AS (select year(`sell`.`Time`) AS `Year`,month(`sell`.`Time`) AS `Month`,dayofmonth(`sell`.`Time`) AS `Day`,sum(`sell`.`Sum`) AS `Income` from `sell` group by `sell`.`Time`);

SET FOREIGN_KEY_CHECKS = 1;
