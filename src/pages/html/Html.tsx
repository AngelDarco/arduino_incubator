import './Html.scss';
import Images from '../../assets/videos/css/Images';

const Html = ()=>{
    return(
    <div className="containerHtml">
        <div className="frame">
           <img src={Images.book} alt="" />
           <img src={Images.card} alt="No Image"/>
        </div>
    </div>
    )
}

export default Html;