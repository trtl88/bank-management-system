# Bank Account Management System

A console-based banking system written in C that supports full account management, transactions, and transaction history tracking.

## Features

- **Authentication** – Secure login system using a credentials file
- **Account Management** – Add, delete, search, and modify accounts
- **Transactions** – Deposit, withdraw, and transfer funds between accounts
- **Transaction History** – View last 5 transactions per account
- **Sorting & Reporting** – Print all accounts sorted by name, balance, or date opened
- **Data Persistence** – All changes are saved to local files

## How It Works

Account data is stored in a CSV file (`accounts.txt`) and loaded into memory on startup. Each account also has a dedicated transaction log file. All operations prompt the user to save or discard changes before writing to disk.

## Getting Started

### Compile

```bash
gcc main.c -o bank
```

### Run

```bash
./bank
```

### Login

On startup, the system prompts for a username and password stored in `users.txt`:

```
username password
```

## File Structure

```
├── main.c              # Main source file
├── accounts.txt        # Stores all account records
├── users.txt           # Stores login credentials
└── <AccNo>.txt         # Transaction log per account
```

## Account Fields

| Field | Description |
|---|---|
| Account Number | 10-digit unique identifier |
| Name | Full name (letters only) |
| Email | Valid email address |
| Balance | Current account balance |
| Mobile | 11-digit mobile number |
| Date Opened | Auto-set to current month and year |

## Limitations

- Supports up to 100 accounts in memory
- Maximum transaction amount is $10,000
- Accounts must have zero balance before deletion

## Testing

Sample data files are included in the repo to test the system.

**Login credentials** (`users.txt`):
| Username | Password |
|---|---|
| (check users.txt) | (check users.txt) |

**Test accounts** (`accounts.txt`):
- Account No: `1234567890`
- Account No: `9780134567`

**Sample transaction logs** are included for both test accounts.
