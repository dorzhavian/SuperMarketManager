# SuperMarket Management System

C-based supermarket management platform designed to handle customer interactions, product management, and checkout processes. This project was developed as part of a software engineering course intro to C.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Description
The SuperMarket Management System allows users to manage products, register customers, track shopping carts, and handle purchases. It emphasizes efficient memory management and modular code structure.

## Features
- **Customer Management**: Register customers with unique IDs and names, manage their shopping carts, and handle customer-specific purchases.
- **Product Management**: Add and update products, display all products, and filter products by type.
- **Shopping Cart**: Add items to shopping carts, update quantities, and process payments.
- **Memory Management**: Dynamic memory allocation and deallocation to prevent memory leaks.
- **Interactive Menu**: Options include:

  - `0) Show super market`
  - `1) Add product`
  - `2) Add customer`
  - `3) Customer shopping`
  - `4) Print shopping cart`
  - `5) Customer shopping cart managment`
  - `6) Print product by type`
  - `-1) Exit`

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/dor_zhavian/SuperMarketManagement.git
    ```
2. Navigate to the project directory.

## Usage
1. Compile the project using GCC:
    ```bash
    gcc -o supermarket manager.c superMarket.c product.c shoppingCart.c shoppingItem.c customer.c date.c functions.c
    ```
2. Run the compiled program:
    ```bash
    ./supermarket
    ```
3. Follow the menu prompts to interact with the system.

## Project Structure
- `manager.c / manager.h` - Main menu and high-level control.
- `superMarket.c / superMarket.h` - Supermarket-level management, including customer and product handling.
- `product.c / product.h` - Product attributes and operations.
- `shoppingCart.c / shoppingCart.h` - Shopping cart functionality for customers.
- `shoppingItem.c / shoppingItem.h` - Management of individual shopping items.
- `customer.c / customer.h` - Customer registration and interaction.
- `date.c / date.h` - Date validation and formatting.
- `functions.c / functions.h` - Utility functions such as safeRealloc, string handling, and validation.

## Contact
For questions or support, contact dorzhavian@gmail.com / talman222@gmail.com

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## All rights reserved to Dor Zhavian & Tal Fridman 
