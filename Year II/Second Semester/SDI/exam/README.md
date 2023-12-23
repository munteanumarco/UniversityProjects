# Examination Session - 27 June 2023

### 27.06.2023

**Theory exam (`10 minutes`)**: [Click here](https://forms.gle/VfncmJWi3jpYF34g6).

**Practical exam (`3 hours`):**

You have to write a full stack application that examiners can use to grade their students.

Recall that each functionality is worth **1 snowflake**. Your snowflakes are then converted to **points**. 

Please implement **exactly** what is asked, **nothing more** and **nothing less**. You need to present the functionalities in the order that they are listed in and each one has to be perfectly implemented for you to receive the snowflake for it. 

If something is ambiguous then you are expected to make the best decision according to what was discussed during the lectures and labs. If things are still ambiguous, then any decision will be accepted.

You should have persistence to a database for all added data, so restarting the application should keep the data. You must commit and push everything to the github repository created by accepting the assignment (link on Teams) in order for it to be considered.

1. Display the following table in plain HTML when visiting the `/` route. You do not need to color the rows, but the borders must look like they do here, as does the text:

    |  **#**  | **Examination title** | **Dashboard link** | **Meanest examiner** |
    |---------|----------|----------|----------|
    | **1** |          |          |          |
    | **2** |          |          |          |
    
2. Add an `h1` tag above the table with the contents **Grading app** and a button below with the content **Create examination**.

3. When clicking on the **Create examination** button, you should be redirected to the route `/examination/create`. We will call this the **Examination Creation Page**, or `ECP`. There should be a form containing the appropriate HTML elements for specifying the title and `3` examiner names. There should be a submit button. On submit, validate that none of the entries are empty and that the `3` examiner names are unique within this form, displaying appropriate error messages if not. The button should not do anything else at this point. 

4. When clicking the submit button on the `ECP`, if everything is valid, the user should be redirected to `/examination/dashboard/<GUID-m>`, where `<GUID-m>` is a random GUID / UUID. We will call this the **Examination Dashboard Page**, or `EDP`. This page should display an `h1` with the contents **Dashboard for `<examination title>`** and an ordered list of the examiner names, each one hyperlinked to the route `/examination/session/<GUID-m>/grading/<GUID-e>`, where `<GUID-e>` is a different GUID for each examiner. We will call this the **Examiner Gradebook Page**, or `EGP`.

5. The `/` route should be modified to display all the added examinations in the table, with the title in the title column and the `<GUID-m>` hyperlinked to `/examination/dashboard/<GUID-m>` in the Dashboard link column. Leave the last column empty for now.

6. When the user accesses the `EGP`, show an error message if any of the two GUIDs are not valid. Otherwise, show an `h1` with the contents **Gradebook for examiner `<examiner name>`**. Also show a table with the columns `#`, `Student name`, `Grade`.

7. On the `EDP`, at the bottom of the page, have a table with the columns `#` and `Student name`. Below it, have the appropriate HTML elements for adding a student name. Validate the student name to be non-empty and unique within this examination. Any number of students can be added within the page and the table is updated after each add without refreshing the page. The `#` column will contain the index of each student and it will be filled in automatically.

8. On the `EGP`, allow the examiner to grade each student by displaying in the table their index, their name and having the appropriate HTML elements in the `Grade` column for entering an integer grade between `1` and `10`. Ensure that the grade is valid. Add a **Refresh** button that reloads the table (but not the entire page).

9. Dockerize your application. Running the docker container should start the frontend, the backend and anything else that you need. Everything should be started with a single docker or docker-compose command. If you have done this from the start, you will receive the snowflake now.

10. Add `swagger` for your backend. If you have done this from the start, you will receive the snowflake now.

11. When the user accesses the `EDP`, show an error if the `<GUID-m>` is not valid. Modify the table by adding `3` columns whose headers are the examiner names. Display the grade each examiner has given to each student, if available. Add a "Refresh" button below the table that reloads the table (but not the entire page). The functionality for adding a student should still work.

12. Add another column to the `EDP` table which displays the average grade for each student. If not all examiners have given a grade, display "Pending" and make the background color red.

13. Below the table on the `EDP`, show a paragraph with the contents **Percentage of students that have been graded by all examiners: `<percentage>`**. Make the background color of the `<percentage>` text green if it is `100%` and red otherwise. The **Refresh** button should update this as well.

14. Remove the **Refresh** button on the `EDP`. Use web sockets to update the information for all viewers in real time.
    
15. Display the names of the meanest examiners on the last column in the table on the `/` route. The meanest examiner for an examination is defined as the examiner who has given the most grades below `5`. In case of equality, display any one of them.
