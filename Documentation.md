# IP2: Singly LinkedList Project Documentation

This project implements a **Singly Linked List** as an **Abstract Data Type (ADT)** in C++.

## Architecture: Pimpl Idiom
The project utilizes the **Pimpl (Pointer to Implementation)** design pattern to achieve complete encapsulation and internalize implementation details.
*   **Separation of Concerns:** The public interface (`LinkedList.h`) contains no data members other than a private pointer to the implementation class.
*   **ABI Stability:** Internal changes to the data structure (e.g., adding a `tail` pointer) do not require recompilation of client code using the header.
*   **Encapsulation:** The `Node` structure and `Impl` logic are hidden within the `.cpp` file, preventing unauthorized access to internal memory.

## Implemented Operations (CRUD/DAVE)

| Operation | Method / Operator | Description |
| :--- | :--- | :--- |
| **Create** | `insertStart(int)`, `+=` | Inserts a new element at the head. Throws if value exists. |
| **Read** | `toString()`, `display()`, `[]` | Returns string info, prints to stdout, or finds value index. |
| **Update** | `update(old, new)`, `%=` | Replaces an existing value with a new one. |
| **Delete** | `deleteStart()`, `-=` | Removes the first element from the list. |
| **Clear** | `operator!` | Wipes the entire list and safely deallocates all memory. |

## Exception Handling
1.  **`DuplicateValueException` (Custom):** Derived from `std::runtime_error`. Thrown during insertion if the value is already present, ensuring uniqueness.
2.  **`std::out_of_range`:** Thrown when attempting to delete from an empty list.
3.  **`std::invalid_argument`:** Thrown when attempting to update a value that does not exist in the list.

## Object Management (Deep Copy)
*   **Deep Copy:** Both the **Copy Constructor** and **Assignment Operator** perform deep copies of the nodes to ensure independent object states and avoid pointer aliasing.
*   **Destructor:** Properly traverses the list to `delete` every dynamically allocated `Node`, preventing memory leaks.

## Comparison Logic
The list implements all **six comparison operators** (`==`, `!=`, `<`, `<=`, `>`, `>=`). Comparisons are performed element by element, allowing lists to be logically aligned and sorted.

## Build Instructions
Use the provided `makefile.txt` to manage the project building and execution from the command line:

*   **Build everything:** `make -f makefile.txt rebuild`
*   **Run Demo:** `make -f makefile.txt run_demo`
*   **Run Tests:** `make -f makefile.txt run_test` (Generates the required `log.txt`)
*   **Clean:** `make -f makefile.txt clean`

---