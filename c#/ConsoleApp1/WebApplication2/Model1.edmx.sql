
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 04/01/2019 12:30:50
-- Generated from EDMX file: C:\Users\Joanna Ruth\Documents\NCRWork\c#\ConsoleApp1\WebApplication2\Model1.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [ncrdb];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------


-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[emp]', 'U') IS NOT NULL
    DROP TABLE [dbo].[emp];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'students'
CREATE TABLE [dbo].[students] (
    [Id] int IDENTITY(1,1) NOT NULL
);
GO

-- Creating table 'emps'
CREATE TABLE [dbo].[emps] (
    [id] int  NOT NULL,
    [name] varchar(50)  NULL,
    [salary] int  NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'students'
ALTER TABLE [dbo].[students]
ADD CONSTRAINT [PK_students]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [id] in table 'emps'
ALTER TABLE [dbo].[emps]
ADD CONSTRAINT [PK_emps]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------