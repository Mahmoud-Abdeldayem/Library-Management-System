# Library-Management-System
The Library Management System is a C++ program that allows users to manage a library's collection of books. It provides functionality for login, book management, and user actions such as checking out books, returning books, and searching for books.

## Concepts : 
- OOP 
- SOLID Principles
- File Handling
- Exception Handling
- Basic Data Structures
- Basic Algorithms

## Functionality :

The Library Management System provides the following functionality:

1. **Login**: Users and administrators can log in to the system using their credentials. The system verifies the entered username and password against the stored user and admin data.

2. **Admin Actions**:
   - **Add a Book**: Administrators can add a book to the library's inventory by providing the book's details such as title, author, and ISBN.
   - **Delete a Book**: Administrators can remove a book from the library's inventory by specifying the book's unique identifier (Book Id).

3. **User Actions**:
   - **Checkout a Book**: Users can check out a book from the library by providing the book's unique identifier (Book Id). The system marks the book as checked out and associates it with the user.
   - **Return a Book**: Users can return a book they have checked out. The system updates the book's status and removes the association with the user.
   - **Search for a Book**: Users can search for a book in the library's inventory by title. The system displays the matching books with their details.

