USE FITNESSTRACKER;
DROP TABLE IF EXISTS versionDb;
DROP TABLE IF EXISTS procedureAndVersions;
GO
-- modify type of a column 
GO
CREATE OR ALTER PROCEDURE setAchievementDateToDateTime
AS
	ALTER TABLE Unlocked
	ALTER COLUMN currentDate DATETIME
GO
CREATE OR ALTER PROCEDURE setAchievementDateTimeToDate
AS
	ALTER TABLE Unlocked
	ALTER COLUMN currentDate DATE
GO
-- add / remove column 
CREATE OR ALTER PROCEDURE addUserTrainingExperience
AS
	ALTER TABLE AppUser
	ADD trainingExperience INT
GO
CREATE OR ALTER PROCEDURE removeUserTrainingExperience
AS
	ALTER TABLE AppUser
	DROP COLUMN trainingExperience
GO
-- add / remove default constraint
CREATE OR ALTER PROCEDURE addDefaultToTrainingExperienceForUser
AS
	ALTER TABLE AppUser
	ADD CONSTRAINT default_exp DEFAULT(0) FOR trainingExperience
GO
CREATE OR ALTER PROCEDURE removeDefaultToTrainingExperienceForUser
AS
	ALTER TABLE AppUser
	DROP CONSTRAINT default_exp
GO
-- create / drop table
CREATE OR ALTER PROCEDURE addAppManagers
AS
	CREATE TABLE AppManager(
		managerId SMALLINT NOT NULL,
		managerName VARCHAR(64) NOT NULL,
		managerRole VARCHAR(64) NOT NULL,
		managerSalary INT,
		userId SMALLINT,
		CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(managerId)
	)
GO
CREATE OR ALTER PROCEDURE removeAppManagers
AS
	DROP TABLE AppManager
GO

-- add / remove primary key
CREATE OR ALTER PROCEDURE addRoleAndNamePrimaryKeyManager
AS
	ALTER TABLE AppManager
	DROP CONSTRAINT MANAGER_PRIMARY_KEY
	ALTER TABLE AppManager
	ADD CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(managerName, managerRole)
GO
CREATE OR ALTER PROCEDURE removeRoleAndNamePrimaryKeyManager
AS 
	ALTER TABLE AppManager
	DROP CONSTRAINT MANAGER_PRIMARY_KEY
	ALTER TABLE AppManager
	ADD CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(managerId)
GO
-- add remove candidate key
CREATE OR ALTER PROCEDURE addCandidateKeyAppUser
AS
	ALTER TABLE AppUser
	ADD CONSTRAINT USER_CANDIDATE_KEY UNIQUE(uName, email, age)
GO
CREATE OR ALTER PROCEDURE removeCandidateKeyAppUser
AS
	ALTER TABLE AppUser
	DROP CONSTRAINT USER_CANDIDATE_KEY
GO
-- add remove foreign key
CREATE OR ALTER PROCEDURE addForeignKeyAppManagers 
AS 
	ALTER TABLE AppManager
	ADD CONSTRAINT APP_MANAGER_FOREIGN_KEY FOREIGN KEY(userId) REFERENCES AppUser(userId)
GO
CREATE OR ALTER PROCEDURE removeForeignKeyAppManagers 
AS 
	ALTER TABLE AppManager
	DROP CONSTRAINT APP_MANAGER_FOREIGN_KEY
GO
-- table that contains the current version of the database

CREATE TABLE versionDb (
	currentVersion INT
)

INSERT INTO versionDb (currentVersion) VALUES (1) -- initial version 1


-- table that contains initial version, version after the procedure exec and the name of the procedure
CREATE TABLE procedureAndVersions (
	initialVersion INT,
	finalVersion INT,
	procedure_name VARCHAR(256),
	PRIMARY KEY(initialVersion, finalVersion)
)

INSERT INTO procedureAndVersions
VALUES
	(1, 2, 'setAchievementDateToDateTime'),
	(2, 1, 'setAchievementDateTimeToDate'),
	(2, 3, 'addUserTrainingExperience'), 
	(3, 2, 'removeUserTrainingExperience'),
	(3, 4, 'addDefaultToTrainingExperienceForUser'),
	(4, 3, 'removeDefaultToTrainingExperienceForUser'),
	(4, 5, 'addAppManagers'),
	(5, 4, 'removeAppManagers'),
	(5, 6, 'addRoleAndNamePrimaryKeyManager'),
	(6, 5, 'removeRoleAndNamePrimaryKeyManager'),
	(6, 7, 'addCandidateKeyAppUser'),
	(7, 6, 'removeCandidateKeyAppUser'),
	(7, 8, 'addForeignKeyAppManagers'),
	(8, 7, 'removeForeignKeyAppManagers')

-- procedure to switch to different db versions
GO 
CREATE OR ALTER PROCEDURE changeToVersion(@desiredVersion INT)
AS
	DECLARE @currentVersion INT
	DECLARE @procedureName VARCHAR(256)
	SELECT @currentVersion = currentVersion FROM versionDb
	IF (@desiredVersion > (SELECT MAX(finalVersion) FROM procedureAndVersions) OR @desiredVersion < 1)
		RAISERROR('Incorrect version', 10, 1)
	ELSE 
	BEGIN
		IF @desiredVersion = @currentVersion
			PRINT('ALREADY AT DESIRED VERSION!');
		ELSE
		BEGIN
			IF @currentVersion > @desiredVersion
			BEGIN
				WHILE @currentVersion > @desiredVersion
					BEGIN 
						SELECT @procedureName = procedure_name 
						FROM procedureAndVersions 
						WHERE initialVersion = @currentVersion AND finalVersion = @currentVersion - 1
						PRINT('EXECUTING ' + @procedureName);
						EXEC (@procedureName)
						SET @currentVersion = @currentVersion - 1
					END
			END

			IF @currentVersion < @desiredVersion
			BEGIN
				WHILE @currentVersion < @desiredVersion
					BEGIN 
						SELECT @procedureName = procedure_name
						FROM procedureAndVersions
						WHERE initialVersion = @currentVersion AND finalVersion = @currentVersion + 1
						PRINT('EXECUTING ' + @procedureName);
						EXEC (@procedureName)
						SET @currentVersion = @currentVersion + 1
					END
			END

			UPDATE versionDb 
			SET currentVersion = @desiredVersion
		END
	END
GO

EXEC changeToVersion 1

EXEC removeUserTrainingExperience

SELECT *
FROM versionDb