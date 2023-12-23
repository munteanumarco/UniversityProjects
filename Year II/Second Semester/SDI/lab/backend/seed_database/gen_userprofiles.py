from faker import Faker
import random
fake = Faker('ro_RO')


# 20003 - 30002
userId = 20003

MARITAL = []

# Open a file to write the SQL statements
with open("populate_userprofiles.sql", "w") as f:
    # Generate and write INSERT statements in batches of 1000
    for i in range(1, 10000, 1000):
        values = []
        # Generate 1000 records at a time
        for j in range(i, i + 1000):
            
            passwordHash = "VpnGljHfjwFbhOhNTwP9+YA7FWd65DhDSYq2LohO6y0YS/lZmcGT7EukrUS5I1Zz3HChog6V9ExSHGQwZD021Q=="
            passwordSalt = "kCQqoO228KQgYK7g0s46JMIMy8FrjJTrNvJD+t0dhcOcCWahgrSNoDPzRpzpkIsJYH5y4UHs4xfh/zHYDws0IFexPVoArjdnU+VDaxPn2Uuqlamn/kCEdpmADy15JGIOCRhQwGwPVSSWWm3s7OmFFzKCwVJKPKqCu08OgnM+u1Y="
            
            values.append(f"('{userId}', decode('{passwordHash}', 'base64'), decode('{passwordSalt}', 'base64'))")
            userId += 1
        # Write a batch of 1000 records to the file
        f.write(f"INSERT INTO \"UserProfiles\" (\"UserId\", \"Bio\", \"Gender\", \"MaritalStatus\" ) VALUES {', '.join(values)};\n")
