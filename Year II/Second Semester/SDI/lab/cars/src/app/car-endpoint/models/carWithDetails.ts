export interface CarWithDetails {
    id: number,
    model: string,
    manufacturer: string,
    color: string,
    fabricationYear: 0,
    numberOfReviews: 0,
    reviews: [
        {
        id: number,
        title: string,
        description: string,
        score: number,
        date: Date,
        carId: number,
        authorId: number
        }
    ],
    races: 
        {
        id: number,
        name: string,
        city: string,
        country: string,
        userId: number,
        }[]
    
}