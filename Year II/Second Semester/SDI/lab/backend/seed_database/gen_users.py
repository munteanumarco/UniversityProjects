from faker import Faker
import random
fake = Faker('ro_RO')

# Open a file to write the SQL statements
with open("populate_users.sql", "w") as f:
    # Generate and write INSERT statements in batches of 1000
    for i in range(1, 1000001, 1000):
        values = []
        # Generate 1000 records at a time
        for j in range(i, i + 1000):
            first_name = fake.first_name()
            last_name = fake.last_name()
            email = fake.email()
            phone = fake.phone_number()
            values.append(f"('{first_name}', '{last_name}', '{email}', '{phone}')")
        # Write a batch of 1000 records to the file
        f.write(f"INSERT INTO \"Authors\" (\"FirstName\", \"LastName\", \"Email\", \"Phone\") VALUES {', '.join(values)};\n")
