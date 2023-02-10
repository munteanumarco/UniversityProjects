-- UPDATE --

UPDATE Exercise 
SET exDescription = 'Keep the pace high and do not stop!'
WHERE exName = 'Stair Master';

UPDATE WorkoutLog
SET duration = 90
WHERE userId = 8 AND logDate = '2022-02-23';

UPDATE Trainer
SET phone = '0720147567'
WHERE trainerId = 2;

-- DELETE -- 

DELETE FROM WorkoutLog
WHERE duration BETWEEN 110 AND 120;

DELETE FROM Unlocked 
WHERE currentDate < '2000-01-01';


-- QUERIES --

-- Program and user that has workout duration smaller than 60 or before 10 june
SELECT W.programId, W.userId
FROM WorkoutLog W
WHERE W.duration < 60
UNION
SELECT W.programId, W.userId	
FROM WorkoutLog W
WHERE W.logDate < '2022-06-10';


SELECT W.programId, W.userId
FROM WorkoutLog W
WHERE logDate < '2022-06-10' OR duration < 60;


-- User that has over 80kg and under 180 cm of height

SELECT U.uName 
FROM AppUser U
WHERE U.uWeight > 80
INTERSECT
SELECT U.uName 
FROM AppUser U
WHERE U.uHeight < 180


SELECT U.uName 
FROM AppUser U
WHERE U.uWeight > 90 AND U.uName IN ( 
						SELECT U.uName 
						FROM AppUser U
						WHERE U.uHeight < 190
						);



-- Users that have an achievment but are not under 25 years old
SELECT A.uName
FROM AppUser A, Unlocked U
WHERE A.userId = U.userId
GROUP BY A.uName
EXCEPT
SELECT A.uName
FROM AppUser A
WHERE A.age < 25

SELECT A.uName
FROM AppUser A, Unlocked U
WHERE A.userId = U.userId AND A.uName NOT IN 
(
	SELECT A.uName
	FROM AppUser A
	WHERE A.age < 25
)
GROUP BY A.uName;


-- Users that unlocked an achievment before 2022-05-01
SELECT US.uName, A.AchName, U.currentDate
FROM Unlocked U
JOIN Achievement A ON A.achId = U.achId
JOIN AppUser US ON U.userId = US.userId
WHERE U.currentDate < '2022-05-01';


--Trainers and their programs
SELECT T.tName, P.pName
FROM Trainer T
LEFT JOIN Program P ON T.trainerId = P.trainerId;


-- Users and their workouts
SELECT U.uName, P.pName, W.duration
FROM AppUser U
FULL JOIN WorkoutLog W ON U.userId = W.userId
FULL JOIN Program P ON W.programId = P.programId


--Count exercises of each type
SELECT ET.typeName, COUNT(E.exId) AS ExsCount
FROM Exercise E
RIGHT JOIN ExerciseType ET ON E.exTypeId = ET.exTypeId
GROUP BY ET.typeName
ORDER BY ExsCount DESC;


-- Users with more than 350 min of workouts ordered desc
SELECT A.uName, SUM(W.duration) AS TotalMinutes
FROM AppUser A
JOIN WorkoutLog W 
ON W.userId = A.userId
GROUP BY A.uName 
HAVING SUM(W.duration) > 350
ORDER BY TotalMinutes DESC;

-- Trainer with the most workouts
SELECT TOP 1 T.tName, COUNT(*) AS Workouts
FROM WorkoutLog W, Program P, Trainer T
WHERE W.programId = P.programId AND P.trainerId = T.trainerId 
GROUP BY T.tName
ORDER BY Workouts DESC; 

-- Trainers that hold at least 2 programs
SELECT T.tName, COUNT(*) AS NoPrograms
FROM Trainer T
JOIN Program P 
ON T.trainerId = P.trainerId
GROUP BY T.trainerId, T.tName
HAVING COUNT(*) > 1;

-- The users that are at least 20 years old and have at least 3 workouts logged
SELECT A.uName 
FROM AppUser A, WorkoutLog W
WHERE A.userId = W.userId AND A.age >= 20
GROUP BY W.userId, A.uName
HAVING 3 <= (
			SELECT COUNT(*) AS N
			FROM WorkoutLog W2
			WHERE W.userId = W2.userId
			);

-- The achievment owned by most of users: 
SELECT A.AchName, A.AchDescription
FROM Achievement A
WHERE A.achId IN (
				SELECT TOP 1 U.achId
				FROM Unlocked U
				GROUP BY U.achId
				ORDER BY COUNT(*) DESC
				);

-- Programs performed by clients that have 35 years or more
SELECT P.pName
FROM Program P
WHERE P.programId IN (
	SELECT W.programId
	FROM WorkoutLog W
	WHERE W.userId IN (
		SELECT A.userId
		FROM AppUser A
		WHERE A.age >= 35
		)
	);
	

--The longest workout for each user that has at least one workout
SELECT A.uName, Q.MaxDur 
FROM ( 
	SELECT W.userId, MAX(W.duration) as MaxDur
	FROM WorkoutLog W
	GROUP BY W.userId
	) AS Q, AppUser A
WHERE A.userId = Q.userId;


-- Medals for each achievment
SELECT A.AchName, A.AchDescription, Q.NoAch
FROM (
	SELECT U.achId, COUNT(*) AS NoAch
	FROM Unlocked U
	GROUP BY U.achId
) AS Q, Achievement A
WHERE A.achId = Q.achId;

--Trainers that hold at least 1 program
SELECT T.tName, T.email
FROM Trainer T
WHERE EXISTS (
	SELECT P.pName
	FROM Program P
	WHERE P.trainerId = T.trainerId
);

-- Exercise types that have at least one exercise
SELECT ET.typeName
FROM ExerciseType ET
WHERE EXISTS (
	SELECT E.exName
	FROM Exercise E
	WHERE E.exTypeId = ET.exTypeId
);


-- Users that are older than any user with the height of 180-185
SELECT A.uName, A.age
FROM AppUser A
WHERE A.age > ANY 
	(SELECT A2.age
	 FROM AppUser A2
	 WHERE A2.uHeight BETWEEN 180 AND 185);

SELECT A.uName, A.age
FROM AppUser A
WHERE A.age > 
	(SELECT MIN(A2.age)
	 FROM AppUser A2
	 WHERE A2.uHeight BETWEEN 180 AND 185);


-- Achievments from 2022-09-01 to 2022-10-31
SELECT A.AchName
FROM Achievement A
WHERE A.achId = ANY 
	(SELECT U.achId
	 FROM Unlocked U
	 WHERE U.currentDate BETWEEN '2022-09-01' AND '2022-10-31'
);

SELECT A.AchName
FROM Achievement A
WHERE A.achId IN 
	(SELECT U.achId
	 FROM Unlocked U
	 WHERE U.currentDate BETWEEN '2022-09-01' AND '2022-10-31'
);


 -- Users that are taller than all users with the weight of 70-80kg
SELECT A.uName, A.uHeight
FROM AppUser A
WHERE A.uHeight > ALL 
	(SELECT A2.uHeight
	 FROM AppUser A2
	 WHERE A2.uWeight BETWEEN 70 AND 80);


SELECT A.uName, A.uHeight
FROM AppUser A
WHERE A.uHeight > 
	(SELECT MAX(A2.uHeight)
	 FROM AppUser A2
	 WHERE A2.uWeight BETWEEN 70 AND 80);



-- Users with height different from 170-185
SELECT A.uName, A.uHeight
FROM AppUser A
WHERE A.userId <> ALL
	(SELECT A2.userId
	 FROM AppUser A2
	 WHERE A2.uHeight BETWEEN 170 AND 185);


SELECT A.uName, A.uHeight
FROM AppUser A
WHERE A.userId NOT IN 
	(SELECT A2.userId
	 FROM AppUser A2
	 WHERE A2.uHeight BETWEEN 170 AND 185);







