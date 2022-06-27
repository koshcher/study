package main

import (
	"errors"
	"net/http"

	"github.com/gin-gonic/gin"
	// 	"errors"
)

type book struct {
	ID     string `json:"id"`
	Title  string `json:"title"`
	Author string `json:"author"`
	Count  int    `json:"count"`
}

var books = []book{
	{ID: "1", Title: "Book 1", Author: "I", Count: 10},
	{ID: "2", Title: "Babooooooooook", Author: "You", Count: 20},
	{ID: "3", Title: "No book", Author: "He", Count: 15},
}

func getBooks(context *gin.Context) {
	context.IndentedJSON(http.StatusOK, books)
}

func bookById(context *gin.Context) {
	id := context.Param("id")
	book, err := getBookById(id)

	if err != nil {
		context.IndentedJSON(http.StatusNotFound, gin.H{"message": "Book not found"})
		return
	}

	context.IndentedJSON(http.StatusOK, book)
}

func checkoutBook(context *gin.Context) {
	id, ok := context.GetQuery("id")
	if !ok {
		context.IndentedJSON(http.StatusBadRequest, gin.H{"message": "Missing id parameter"})
		return
	}

	book, err := getBookById(id)

	if err != nil {
		context.IndentedJSON(http.StatusNotFound, gin.H{"message": "Book not found"})
		return
	}

	if book.Count <= 0 {
		context.IndentedJSON(http.StatusBadRequest, gin.H{"message": "Book not available"})
		return
	}

	book.Count += 1
	context.IndentedJSON(http.StatusOK, book)
}

func getBookById(id string) (*book, error) {
	for i, b := range books {
		if b.ID == id {
			return &books[i], nil
		}
	}

	return nil, errors.New("book not found")
}

func addBook(context *gin.Context) {
	var newBook book

	if err := context.BindJSON(&newBook); err != nil {
		return
	}

	books = append(books, newBook)
	context.IndentedJSON(http.StatusCreated, newBook)
}

func main() {
	router := gin.Default()
	router.GET("/books", getBooks)
	router.POST("/books", addBook)
	router.GET("/books/:id", bookById)
	router.PATCH("/checkout", checkoutBook)
	router.Run("localhost:8080")
}
