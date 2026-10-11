# CALCULATRICE

A small graphical calculator written in C with **GTK+ 2**. It takes two integers and displays their sum.

Built as *Project 3* for the INFO0030 course (2020).

## Features

- GTK window with two input fields (`Nombre 1`, `Nombre 2`), an **Additionner** button and a result label
- Input validation: each field must contain an integer (an optional leading `-` is allowed)
- Error popups when a field is empty or contains anything other than an integer
- Doxygen-documented API

> The user interface is in French.

## Requirements

- `gcc` (C99)
- GTK+ 2 development headers
- `pkg-config`
- `doxygen` (optional, for the documentation)

Installing GTK+ 2:

```bash
# Debian / Ubuntu
sudo apt install build-essential pkg-config libgtk2.0-dev

# macOS (Homebrew)
brew install gtk+ pkg-config
```

## Build & run

```bash
make            # builds the `calculatrice` executable
./calculatrice
```

Other targets:

```bash
make doc        # generates the HTML documentation in doc/ (Doxygen, French output)
make clean      # removes object files, the executable and doc/
```

## Project structure

| File             | Description                                                          |
|------------------|----------------------------------------------------------------------|
| `main.c`         | Builds the window layout (boxes, labels, entries, button), starts the GTK main loop |
| `calculatrice.c` | Window creation, error popup, input validation and addition logic    |
| `calculatrice.h` | Function prototypes with Doxygen comments                            |
| `Makefile`       | Build, documentation and cleanup rules                               |
| `Doxyfile`       | Doxygen configuration                                                |

## API overview

| Function                                   | Role                                                         |
|--------------------------------------------|--------------------------------------------------------------|
| `creer_fenetre(const char *nom)`           | Creates the top-level window, which quits GTK when closed    |
| `bouton_addition(void)`                    | Creates the **Additionner** button wired to `verification_champs` |
| `verification_champs(void)`                | Reads both entries, validates them and shows the result or an error |
| `verification_entier(const char *Nombre)`  | Returns `0` if the string is an integer, `-1` otherwise       |
| `resultat_addition(GtkWidget *, int, int)` | Writes `La somme vaut : <sum>` into the result label          |
| `erreur_popup(const char *, const char *)` | Shows a modal error dialog with an **OK** button             |
| `detruire_popup(GtkWidget *, gpointer)`    | Closes the error dialog                                      |

## Known limitations

- Only addition is supported.
- Uses deprecated GTK+ 2 APIs (`gtk_vbox_new`, `gtk_signal_connect`, …); it will not build against GTK 3/4.
- Integer overflow is not checked (`atoi` is used for conversion).
- When a field is empty, the error popup is shown but the computation still runs, because an empty string (or a lone `-`) passes `verification_entier`.
