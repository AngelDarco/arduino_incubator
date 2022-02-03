import Book from './book.gif';
import Card from './card.gif';
import Cube from './cube.gif';
import Earth from './earth.gif';
import Loader from './loader.gif';

interface Css {
    book: string,
    card: string,
    cube: string,
    earth: string,
    loader: string
};

export const CssImages:Css = {
    book: Book,
    card: Card,
    cube: Cube,
    earth: Earth,
    loader: Loader,
}

export const CssLinks:Css = {
    book: 'http://darcocorporation.scienceontheweb.net/pages/css/book_cover/',
    card: 'http://darcocorporation.scienceontheweb.net/pages/css/neon_cards/',
    cube: 'http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/',
    earth: 'http://darcocorporation.scienceontheweb.net/pages/css/earth_rotation/',
    loader: 'http://darcocorporation.scienceontheweb.net/pages/css/load_wheel/'
}