USE FITNESS;

DROP TABLE IF EXISTS WorkoutLog;
DROP TABLE IF EXISTS Unlocked;
DROP TABLE IF EXISTS Achievement;
DROP TABLE IF EXISTS AppUser;
DROP TABLE IF EXISTS Exercise;
DROP TABLE IF EXISTS ExerciseType;
DROP TABLE IF EXISTS Program;
DROP TABLE IF EXISTS Trainer;
DROP TABLE IF EXISTS ProgramType;
DROP TABLE IF EXISTS AppManager;
CREATE TABLE AppUser 
(
	userId SMALLINT NOT NULL,
	uName VARCHAR(64) NOT NULL,
	email VARCHAR(64) NOT NULL,
	uPassword VARCHAR(64) NOT NULL,
	age SMALLINT,
	uWeight SMALLINT,
    uHeight SMALLINT,
	PRIMARY KEY(userId)
)

CREATE TABLE AppManager(
	managerId SMALLINT NOT NULL,
	managerName VARCHAR(64) NOT NULL,
	managerRole VARCHAR(64) NOT NULL,
	managerSalary INT,
	CONSTRAINT MANAGER_PRIMARY_KEY PRIMARY KEY(managerId)
)


CREATE TABLE Trainer 
(
	trainerId SMALLINT NOT NULL,
	tName VARCHAR(64) NOT NULL,
	email VARCHAR(64) NOT NULL,
	phone VARCHAR(64) NOT NULL,
	age SMALLINT,
	PRIMARY KEY(trainerId)
)

CREATE TABLE ProgramType 
(
	pTypeId SMALLINT NOT NULL,
	pDescription VARCHAR(128)
	PRIMARY KEY(pTypeId)
)

CREATE TABLE Program 
(
	programId SMALLINT NOT NULL,
	trainerId SMALLINT NOT NULL,
	pName VARCHAR(32) NOT NULL,
	pTypeId SMALLINT NOT NULL,
	PRIMARY KEY(programId),
	FOREIGN KEY(trainerId) REFERENCES Trainer(trainerId)
			ON DELETE CASCADE,
	FOREIGN KEY(pTypeId) REFERENCES ProgramType(pTypeId)
			ON DELETE CASCADE
)


CREATE TABLE Achievement 
(
	achId SMALLINT NOT NULL,
	AchName VARCHAR(32) NOT NULL,
	AchDescription VARCHAR(128) NOT NULL,
	PRIMARY KEY(achId) 
)


CREATE TABLE Unlocked
(
	userId SMALLINT NOT NULL,
	achId SMALLINT NOT NULL,
	currentDate DATE  
	PRIMARY KEY(userId, achId),
	FOREIGN KEY(userId) REFERENCES AppUser(userId),
	FOREIGN KEY(achId) REFERENCES Achievement(achId)
)

CREATE TABLE ExerciseType 
(
	exTypeId SMALLINT,
	typeName VARCHAR(32) NOT NULL,
	PRIMARY KEY(exTypeId)	
)

CREATE TABLE Exercise 
(
	exId SMALLINT NOT NULL,
	exName VARCHAR(32) NOT NULL,
	exDescription VARCHAR(64),
	programId SMALLINT NOT NULL,
	exTypeId SMALLINT,
	PRIMARY KEY(exId),
	FOREIGN KEY(programId) REFERENCES Program(programId),
	FOREIGN KEY(exTypeId) REFERENCES ExerciseType(exTypeId)
)

CREATE TABLE WorkoutLog 
(
	userId SMALLINT NOT NULL,
	programId SMALLINT NOT NULL,
	logDate DATE,
	duration SMALLINT NOT NULL,
	PRIMARY KEY(userId, programId, logDate),
	FOREIGN KEY(userId) REFERENCES AppUser(userId),
	FOREIGN KEY(programId) REFERENCES Program(programId)
)

insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (1, 'Axel Almak', 'aalmak0@narod.ru', 'df8b696d2bec6947ea3cca98c869b44c', 29, 86, 168);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (2, 'Bobbye Signori', 'bsignori1@deliciousdays.com', '5b33e41935cf48cf0704aa2ca14c7273', 39, 90, 170);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (3, 'Melanie Duny', 'mduny2@pagesperso-orange.fr', '36239c512ca50d917c672f7bb9a38ab3', 32, 65, 188);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (4, 'Elena Worssam', 'eworssam3@ftc.gov', 'b5c2fa98b1b12e2b071488f5993c88cc', 33, 67, 175);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (5, 'Garald Whichelow', 'gwhichelow4@deliciousdays.com', 'e667da14cf8d7fc4eb14e5d1a0e203e4', 24, 78, 156);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (6, 'Llywellyn Joberne', 'ljoberne5@dell.com', 'af1310abd560cf28ba31dc9715d751e7', 27, 65, 160);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (7, 'Dorolisa MacGarrity', 'dmacgarrity6@businesswire.com', '61515da355349abc4a0f4edb45ec5036', 38, 72, 160);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (8, 'Gretel Durward', 'gdurward7@cbslocal.com', '57cb2289192dedb7f8f08023fc448f57', 33, 63, 162);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (9, 'Arne Waplington', 'awaplington8@flickr.com', '82d8fe2efa8d4d283882e75e20356fae', 30, 93, 169);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (10, 'Saxon Asif', 'sasif9@mysql.com', 'b450629aa0a46aa24d7a8eb9f4718234', 26, 97, 179);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (11, 'Grata Kirdsch', 'gkirdscha@ameblo.jp', '3bb8f95e131540cfbbf6f298786843ea', 24, 61, 176);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (12, 'Kettie Acedo', 'kacedob@sphinn.com', 'b49ab20219e980796e4de30d6ab397db', 28, 93, 169);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (13, 'Corabel Hutchings', 'chutchingsc@yolasite.com', '43d493ca07d54bc31292e1d07fba065e', 24, 92, 172);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (14, 'Jordain Rhubottom', 'jrhubottomd@imageshack.us', 'b4f7f2d7336cb84832c4c60ae4bca825', 21, 96, 189);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (15, 'Rosa Harlowe', 'rharlowee@altervista.org', '35408ec4d2687e797bff35cc04ae2212', 27, 91, 184);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (16, 'Rania McGreary', 'rmcgrearyf@toplist.cz', '1b8926bfd3841460f3df2c481528d74d', 23, 67, 155);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (17, 'Brittney O''Canavan', 'bocanavang@sbwire.com', '9d17c8fedca77f97834f10c95ead8a4a', 20, 92, 186);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (18, 'Laurice Rosenhaus', 'lrosenhaush@tuttocitta.it', '066dc4679a46cd57aa22a5b8e40780dc', 21, 78, 155);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (19, 'Dermot Sorrill', 'dsorrilli@eventbrite.com', 'e8f07505f702b3a8b03ec2793377dd58', 38, 90, 188);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (20, 'Tye Priddie', 'tpriddiej@umn.edu', '27d29b7c1d552062fd2667cac1954b5f', 18, 89, 161);
insert into AppUser (userId, uName, email, uPassword, age, uWeight, uHeight) values (25, 'Tye Jonnie', 'tpriddiej@umn.edu', '27d29b7c1d5123062fd2662451254b5f', 19, 69, 171);


INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (1, 'Sosanna Milvarnie', 'smilvarnie0@twitpic.com', '0708174871',20);
INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (2, 'Tanney Ladbrooke', 'tladbrooke1@indiatimes.com', '0773826080',22);
INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (3, 'Alfonso Spence', 'aspence2@behance.net', '0788861116',24);
INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (4, 'Abigael O Growgane', 'aogrowgane3@sfgate.com', '0773960550',25);
INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (5, 'Thekla Gozzard', 'tgozzard4@mozilla.com', '0793377107',28);
INSERT INTO Trainer (trainerId, tName, email, phone, age) VALUES (6, 'Joumi Sasuke', 'joumi@gmail.com', '0791237107',31);

INSERT INTO ProgramType (pTypeId, pDescription) VALUES (1, 'High intentsity cardio')
INSERT INTO ProgramType (pTypeId, pDescription) VALUES (2, 'Upper body')
INSERT INTO ProgramType (pTypeId, pDescription) VALUES (3, 'Lower body')
INSERT INTO ProgramType (pTypeId, pDescription) VALUES (4, 'Low intentsity cardio')

INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (1, 1, 'Cardio A', 1)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (2, 2, 'Cardio B', 4)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (3, 3, 'Push A', 2)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (4, 4, 'Pull A', 2)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (5, 5, 'Legs A', 3)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (6, 1, 'Push B', 2)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (7, 2, 'Pull B', 2)
INSERT INTO Program (programId, trainerId, pName, pTypeId) VALUES (8, 3, 'Legs B', 3)


INSERT INTO Achievement (achId, AchName, AchDescription) VALUES (1, 'Polar bear', 'Done 10 workouts before 8AM!')
INSERT INTO Achievement (achId, AchName, AchDescription) VALUES (2, 'Consistent', 'Completed 100 workouts')
INSERT INTO Achievement (achId, AchName, AchDescription) VALUES (3, 'Warrior', 'Done 2 workouts in a single day!')
INSERT INTO Achievement (achId, AchName, AchDescription) VALUES (4, 'The runner', 'Done 100km of cardio')


INSERT INTO Unlocked (userId, achId, currentDate) VALUES (1, 1, '2022-10-04')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (2, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (1, 3, '2021-08-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (2, 2, '2020-11-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (3, 2, '2022-06-22')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (5, 4, '2022-05-24')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (6, 1, '2022-10-04')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (7, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (9, 2, '2020-11-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (10, 2, '2022-06-22')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (11, 4, '2022-05-24')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (6, 2, '2022-06-22')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (9, 1, '2022-10-04')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (10, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (11, 3, '2021-08-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (12, 1, '2022-10-04')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (20, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (13, 3, '2021-08-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (12, 2, '2020-11-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (13, 2, '2022-06-22')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (15, 4, '2022-05-24')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (16, 1, '2022-10-04')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (17, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (18, 3, '2021-08-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (19, 2, '2020-11-12')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (12, 4, '2022-05-24')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (17, 2, '2022-06-22')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (16, 4, '2022-05-24')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (19, 1, '2022-09-10')
INSERT INTO Unlocked (userId, achId, currentDate) VALUES (15, 3, '2021-08-12')

INSERT INTO ExerciseType (exTypeId, typeName) VALUES (1, 'Chest')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (2, 'Triceps')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (3, 'Biceps')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (4, 'Back')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (5, 'Hamstrings')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (6, 'Quadriceps')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (7, 'Calves')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (8, 'Shoulders')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (9, 'Treadmill')
INSERT INTO ExerciseType (exTypeId, typeName) VALUES (10, 'Abdominals')

INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (1, 'Flat Benchpress', 'Use the barbell', 3, 1)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (2, 'Incline Benchpress', 'Use the barbell', 6, 1)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (3, 'Dumbell Press', 'Use the dumbells', 6, 1)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (4, 'Incline Dumbell Press', 'Use the dumbells', 3, 1)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (5, 'Pec flyes', 'Use the cables', 3, 1)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (6, 'Pullups', 'Pullups with wide grip', 4,4)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (7, 'Wide Lat Pulldowns', 'Use the wide bar attachment', 7, 4)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (8, 'Close Lat Pulldowns', 'Use the close attachment', 4,4)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (9, 'Mid Row', 'Use chest supported row machine', 4,4)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (10, 'Front pulldown', 'Focus on the unilateral contraction of the lats', 7,4)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (11, 'Triceps Extensions', 'Use the rope attachment', 3,2)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (12, 'Close Grip Benchpress', 'Use the close grip in order to focus on the triceps activation', 6,2)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (13, 'Dips', 'Focus on the negative part of the movement', 6,2)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (14, 'Dumbell Curls', 'The tension should be on the biceps at all times.', 4,3)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (15, 'Preacher Curls', 'Use a bench or a machine to support your elbows', 7,3)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (16, 'Cable Curls', 'The tension shoud be on the biceps at all times. Use the cables', 4,3)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (17, 'Pendulum Squats', 'Control the negative part of the movement', 5, 6)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (18, 'Leg press', 'Focus on quadriceps activation', 5, 6)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (19, 'Heck Squats', 'Focus on hamstring activation', 8, 5)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (20, 'Standing Calf Raises', 'Pause at the bottom and control the eccentric', 5, 7)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (29, 'Seated Calf Raises', 'Pause at the bottom and control the eccentric', 8, 7)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (21, 'Leg extensions', 'Get full ROM and control the eccentric', 5, 6)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (22, 'Leg curls', 'Focus on hamstring activation', 5, 5)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (26, 'Standing curls', 'Focus on hamstring activation', 8, 5)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (23, 'Shoulder Press', 'Front delt activation', 3, 8)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (24, 'Lateral Raises', 'Focus on medial delt activation and eccentric', 4, 8)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (25, 'Rear Delt Flyes', 'Keep it light and focus on contraction of the rear delt', 4, 8)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (27, 'Incline Walk', 'Sustained effort', 1, 9)
INSERT INTO Exercise (exId, exName, exDescription, programId, exTypeId) VALUES (28, 'Stair Master', 'Keep the pace high', 2, 9)

INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (16, 8, '2022-03-09', 139);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 5, '2022-03-21', 116);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 3, '2022-05-05', 145);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (5, 8, '2022-01-20', 167);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (6, 1, '2021-11-16', 179);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (11, 6, '2022-10-14', 81);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 6, '2021-11-15', 71);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (7, 6, '2022-11-03', 148);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (7, 2, '2022-01-30', 86);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 2, '2022-04-26', 113);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (8, 5, '2022-09-09', 141);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 8, '2022-08-02', 116);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (11, 6, '2022-09-02', 107);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (4, 2, '2022-09-20', 69);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (6, 5, '2022-07-05', 113);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (19, 1, '2022-03-21', 99);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (20, 4, '2022-07-05', 177);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (15, 3, '2022-08-06', 167);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (17, 1, '2021-12-16', 70);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (5, 1, '2022-09-10', 127);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (18, 6, '2022-01-30', 82);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (12, 1, '2022-05-27', 65);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (4, 1, '2020-11-12', 119);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (20, 5, '2022-01-11', 122);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (8, 1, '2022-04-21', 71);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (9, 4, '2022-04-29', 180);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (9, 5, '2022-06-15', 80);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (19, 2, '2022-02-27', 104);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (11, 5, '2022-07-30', 100);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (14, 6, '2022-05-19', 127);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (20, 4, '2022-03-26', 179);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (6, 2, '2022-07-21', 71);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (15, 7, '2022-08-04', 157);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (19, 8, '2022-02-28', 172);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (12, 6, '2022-08-16', 126);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (6, 2, '2022-10-21', 104);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (17, 8, '2021-11-13', 69);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (14, 4, '2022-03-25', 119);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (14, 3, '2022-02-03', 96);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (9, 4, '2022-06-25', 160);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (5, 6, '2022-03-24', 106);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (8, 2, '2021-12-07', 67);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (11, 1, '2022-06-30', 125);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (1, 6, '2022-06-16', 180);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (8, 2, '2022-02-23', 61);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (9, 4, '2022-01-08', 120);
INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (14, 4, '2022-12-25', 119);
--INSERT INTO WorkoutLog (userId, programId, logDate, duration) VALUES (99, 4, '2022-12-25', 119);