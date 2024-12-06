
Library Management System
=========================

A **Library Management System** implemented in C that helps manage library operations such as adding books, issuing books, searching for books, displaying issued books, returning books, and viewing the book list.

---

## Features

1. **Add Books**:
   - Input and store book details such as book ID, title, author, etc.
   - Ensures unique book entries in the database.

2. **Issue Books**:
   - Assign books to users with details like issuer's name, issue date, and return date.
   - Checks the availability of books before issuance.

3. **Search Books**:
   - Allows users to search for books in the database by various criteria.

4. **Show Issued Books**:
   - Displays all currently issued books along with their details.

5. **Return Books**:
   - Processes the return of books and updates their availability in the database.

6. **Book List**:
   - Displays all books available in the library repository.

---

## Program Structure

- **Menu-Driven Interface**:
  - A simple and interactive console-based menu to navigate through options.
- **Data Handling**:
  - Uses file operations to store and retrieve book details, ensuring data persistence.
- **Custom Data Structures**:
  - `struct book_detail`: Stores book details like ID, name, and author.
  - `struct issue_book`: Manages issued book records, including issuer details and dates.

---

## How to Run

1. **Requirements**:
   - A C compiler (e.g., GCC).
   - Basic knowledge of running C programs.

2. **Steps**:
   - Compile the program using:
     ```bash
     gcc LibMan.c -o libman
     ```
   - Run the compiled program:
     ```bash
     ./libman
     ```

3. **Menu Options**:
   - Upon running, the program displays a menu with the following options:
     ```
     1 --> Add Books to Database
     2 --> Issue Books
     3 --> Search Book in Database
     4 --> Show Issued Books
     5 --> Return Book
     6 --> Book List
     ```

---

## File Handling

- All book details and issued records are stored in separate files for persistent storage.
- File operations ensure that data is saved and accessible between program executions.

---

## Contributing

Contributions are welcome! If you'd like to improve this project, feel free to fork the repository and submit a pull request.

---

## License

This project is open-source and available.

---

## Author

**Abhishek Kumar**  
Final-year BCA Student  
[LinkedIn](https://www.linkedin.com/in/at-the-abhishek) | [GitHub](https://github.com/mr-abhi-shek)
