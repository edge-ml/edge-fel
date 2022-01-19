#include "Data.h"

using namespace std;

const vector<double> Data::values_ten = { 1, 2, 2.5, -1, -2, 3.5, 0, -4, -1, 2 };

const vector<double> Data::values_hundred = { -2.002513, 1.456986, -3.675927, 1.204603, -2.358005, -1.436368, 3.884376, -3.077519, 2.405486, 3.449636, 3.175873, -1.450745,
						   1.018076, 2.601166, 3.360496, 1.725507, -1.976595, -3.006324, -3.941639, -3.486634, -3.391173, 1.673422, 0.283105, -1.526038,
						  -3.541132, 2.546888, 3.096766, -3.570857, -1.10204, 0.454013, -2.647407, 2.059799, 3.611786, 3.609037, 3.965181, -3.74101, 2.878393,
						   3.44048, 3.96019, 0.98468, -3.041087, -1.851316, -3.704602, -3.576657, 1.744358, 2.78045, -3.226757, 0.526781, -1.545908, 0.433557,
						   1.314169, 3.837454, -3.646597, -3.979128, 0.670129, -2.250678, 3.532767, -3.697318, -2.209784, 1.917224, 2.388286, 2.833637, -2.783581,
						  -3.864057, 1.809326, -3.983679, 2.468187, -1.893376, 3.911841, -2.895029, -3.121191, -3.799959, 2.153032, 0.578547, 0.447024, -3.522438,
						   3.63805, 2.996742, -2.226916, -2.150376, 0.311752, 3.258009, -1.720835, -1.699474, -1.420944, -3.435247, 3.852508, -2.553622, 1.917332,
						  -3.744665, -3.526519, -1.367193, 0.053053, 2.971178, 2.029162, -3.557223, 0.526768, 1.916743, 3.133562, -3.734832 };

const vector<double> Data::values_thousand = { -0.663823962379408,1.7625959475372648,-3.999085001461241,-1.5813394189452818,-2.8259528734630956,-3.2612912418496176,-2.5099183089786328,-1.235514183655618,-0.8258602061546405,0.31053387202685556,-0.6464438847736416,1.481756003174076,-2.3643820021478605,3.0249394911275633,-3.7808992544165907,1.3637400814272178,-0.6615615810629842,0.46951862756601326,-2.87690449123813,-2.4151880873209697,2.4059565494042934,3.74609260575518,-1.4926065747260573,1.5385809253545126,3.0111132183683065,3.1568533080307786,-3.3196463090417767,-3.687561734136941,-2.641356643483449,3.025140027435305,-3.2132253293355992,-0.6311389999595827,3.6631162412040155,0.2653222797841366,1.5350169116037868,-1.4758749519514964,1.4920074214526693,2.6770053751789833,-3.8536937812464656,2.0011545195597398,3.9108887112519577,1.9853252350387152,-1.7564480634847586,2.314234627611908,-3.174191947378864,-0.4168517905927587,3.2687640247447645,-1.651086813010564,-1.69779729130921,-2.9597714230537786,-3.8450643370376234,1.4306842635191277,-2.3069750719995277,-1.8756267250221903,-0.06741472575729368,-3.573099639063357,0.5929408439361046,-2.826171400753519,0.714444295226274,1.5980668801674494,-3.1813245693773933,-0.6875520974434535,1.5552012618219608,-0.6865658437847788,-3.6003723284313027,0.2871712473240926,1.3103571617583105,0.1191128964664685,3.5567580479265066,0.6924403240159434,3.227215322303068,-2.9002023668301,-2.8857892219939316,2.4591303096761905,-0.8185853041157314,-2.677166423064538,3.420068643168271,-1.2178731220359476,2.0064968250892443,1.8079838828036117,3.0664487296464786,0.9893776564448711,2.0075394722186974,-1.2088132641772598,-1.8405768658797914,3.1670897455685347,-0.5752704810296407,3.7187203771870845,1.3075319825475846,0.9735657616729743,-3.0820322163729985,3.59591406965657,-0.4007029321604758,0.6271169150970541,-0.7349055779097506,-2.1037841580557783,3.2270361644980303,0.5894358933782868,-3.9770373837507282,0.937159308965791,

-1.3868407858232308,0.21646481806087436,3.087536794486196,-1.1418419199800018,3.2682812073583936,0.9868809263344218,-3.8734300572275497,3.4354978699500904,1.5271753401353916,3.978582803611844,-2.6212759332373716,-2.902914002968978,3.4607637042973085,1.5745452919192013,-3.4719986182235,2.043704420819731,2.031009507689971,3.3841962843718667,1.692198069027774,-3.0058323042226824,-3.8409589292816353,-3.7903121049782458,-3.773548095833643,-2.030311459175633,2.880223589463104,0.31064851473322275,0.42257582948612704,2.7362471388768457,-3.006613479040711,-1.766530567910884,0.686074171666303,3.7567659865573964,0.4882417540456796,-3.850821685016456,2.4050613814449306,-2.1362058092718366,2.456841564950233,-0.897114847486626,2.9083348364754293,1.976973141897477,0.4499218719233511,-2.90835819471452,-3.5206584839023067,-3.029252354074101,-3.643584971641906,-3.1400469671512568,-2.1943252911371625,1.7039118430614133,0.47773585643313954,-3.899552158727073,-3.424205762484106,3.738210640002176,0.544803695359537,-2.373654122712076,-1.9813940434374127,1.9506068326007435,-2.4365641511254497,0.6508714181860622,3.7601599127064986,2.774630411920282,-2.0812179268193107,-0.04984228585016037,0.959645747051038,2.63184719640143,-2.745668842831326,-3.851390382580724,-3.4398228502462214,-0.10923911250374552,0.8506356932266428,0.5508114966918507,-1.461100725422714,3.908929235299591,0.6379617539663753,-0.9588706190115968,0.40758575294317456,1.9626754472520167,1.3538631476254768,-1.8806435386975249,-3.4693213245724674,-1.0393264166871496,1.0377400561725159,-2.3186079206812833,2.022044429910511,-3.4677081491670805,-1.9174792113716723,2.4380365099467634,-2.452525739013378,1.115687047039521,0.19736247298986953,3.3984637631948056,-1.8936258361031122,-3.4723112745278097,1.8805277063093557,2.177424236345974,3.2625268200281923,3.4557765535746983,-3.888387416195224,-2.125103311028636,0.9342268560132609,3.5921305655009315,

3.6014089539766374,0.4532255055612513,3.3248507981301962,1.1325296715707003,-0.8799382868700301,-0.11207466322472204,0.834483863359786,0.3963833720685006,3.409451413651629,3.349867485068849,-0.8409950966115609,3.7061002275256945,-2.608354666556285,-2.9893638444829014,-2.9193667356261495,0.04529732541517362,-3.827801557806416,3.583761689741448,2.61692376936586,-3.879848154063021,-2.590429955399558,-1.3434914050653042,-2.952025241512665,2.4759255370126567,-1.2421067785336524,3.5208598586669373,0.6561134395766404,3.0306558752947526,2.757875563137775,3.243138549669194,-0.3209578734655443,0.37077452816298617,2.388828729216315,-1.7142491861268194,-0.07797181904057826,0.7928824611670269,-3.875733795593314,0.7478512655730976,-0.5305892080843337,2.4588842310787316,-1.4780415752370164,3.1431096682012107,0.6228577222762839,-2.5279183869802795,2.3034338706040343,0.8962494163594714,-3.5687258234099763,-0.6384505599909422,1.4325506925234368,3.3488142238202068,-3.9967838008691405,3.814073192248477,-0.9873574820338042,3.7902683068665803,0.8377288077924243,2.6307664638455437,0.5976920376648183,1.0246095864588032,-1.7153897464344485,0.6946667252486636,2.0001741096212795,2.866510691432339,2.0406575077414413,1.584457987578424,2.9158354404367985,-1.4185520253060284,1.366310326300698,-0.3930085086932067,-0.9431779837478622,-0.7135092006225152,-0.7881633322436752,-1.4609284323337848,0.9753549433624116,-0.5580218334298852,3.790416623418018,1.4224071314744888,-2.411440892583113,-0.5863919252157377,-1.2532300818046158,2.3811104316685325,3.039986308507454,3.2307356466109756,1.3017584990020978,-1.8383339037619377,-1.9810663879632822,2.839183541579219,0.2217171704699732,2.4172886720367845,0.5799081375328505,1.865140202300089,0.1520930197124466,2.167071284015104,0.5508639256377243,-0.274320971264153,-1.2584887363737458,-3.454325212666367,-0.9766065653752012,-3.362991378413981,3.86253690984356,-2.54709718935389,

2.494869581764318,2.999693159647185,1.5073060190875465,0.5559553019630057,-2.71222850547513,-0.2649598178935495,-1.23862359075828,-2.1996803374873233,0.740094950126374,-1.5018412983846643,3.330444427746806,3.2770841996124567,-1.9430536497424304,-3.1128695940477664,-2.456298143847097,-0.0033266345689115795,1.8286853437967698,-2.334444492729668,-2.015731532982154,2.813374999490936,-0.6732102538597813,0.9334805372418895,-2.1306708860859995,-3.1842619245936206,0.1268561357482385,-0.1828721036017411,-2.778626847254694,0.974449853923324,0.352080950511505,1.2330987757659546,-2.8436356790027215,2.012222537081951,-2.2236068816006185,0.154814594928264,2.2823682257729514,-3.8213565760655506,-1.405100322190508,2.9833790112008884,2.7576768608165567,0.3075247407563495,2.932866193332104,3.5984479308290123,2.6112559810347307,2.8329235506923096,-3.210052785437213,1.2104346587279284,1.6281359052212236,0.8819265011730373,2.3969220938882243,-3.723430241026926,2.1619098764398395,1.8538288059162156,-1.9224128536131753,-1.9434456094228265,1.0584265394410224,-1.2376203072713476,2.3727094240583,-0.4308301439723419,2.2619953182733754,3.9237742689907256,-1.5980132837287995,-2.855953373935205,3.2104674907941906,0.33247503109898613,3.797922966840658,1.0928352000151778,3.9513041968838314,0.3685664331436129,0.21140747124417025,-2.916576775422641,-1.1543586321289512,-3.7902514616290137,-2.716838563842807,1.9650975416599685,-3.7568024805696894,-1.0676552220500453,2.898770022704353,1.5414217400588344,1.5275371365293484,-2.490905592357513,-0.4647657540126131,0.6526192587543296,3.918013661309642,-2.368750198135025,-2.018136785901161,-1.9026153298167046,2.0013793063839422,-0.3441973805144576,-3.54456449271124,0.06812992488191671,-2.3043186828505924,2.3888339580816815,-1.6213489479418222,-3.779151904363971,0.7474595957169683,2.7507234314495106,-0.9518710075022865,1.9988664858091472,0.08913182637702555,0.32761443969750914,

3.6754745684940193,2.4316871319891744,-3.741415467011408,1.6750980098503607,-0.27998814749195144,3.5803915311607986,-2.2285381254120935,-1.8634238425250738,-3.348208280981904,-0.5710493706897077,-3.1278498878474537,1.0702940848953428,2.423705898989903,1.5744039689614278,2.1296910486061638,-1.2603670412518415,2.7668118642214212,-0.5698498000044596,2.59207896329855,1.01196926899435,-2.8526156106380407,-3.3729048011604164,-3.8533388566959417,-3.4662000188851483,-0.33132949033254544,-3.093264617859276,-3.7777332092106404,2.038891851123739,-0.8411961563148846,1.975507964860201,-0.3807613860283876,-0.399306023993911,-0.17541994625735224,-0.20796858750244773,2.425306736913357,-0.7808598411381134,3.2374892827489843,-3.703511616367713,2.1909947417633493,-2.9948689508980895,0.9481085352966838,-3.9170859093181445,0.30901826061077564,-3.975856347043229,3.609550283921636,3.2432162696222244,2.367735535538155,3.3221945593182998,-2.8355341507328236,-2.7381594410357337,-2.498946616780528,0.9799672183993691,3.246475968066415,3.919641426872589,1.6889796701265274,1.8544032731383622,3.2743456363540355,-0.7930101410310328,-2.001194558199706,-2.612558633703017,-3.044343597330168,2.5008847042626297,-2.8256610126620547,-1.8856201381847946,2.5527134290682465,-1.5153019856463201,3.8593395943435427,-1.8668903827869183,0.26922675976969135,-1.484263910513203,3.2861826493906996,-1.0675468491901245,-0.5312613818146836,0.09834153822689107,3.5110918189577065,-3.7524079498307943,1.7350293090535134,3.1281516343387112,-3.7817022118602495,0.17640997802008584,-1.3920815058397977,2.8759145669246866,0.4681324073801427,1.5218229453019827,-0.3771720003877004,1.026472300170857,-1.6792251865005934,-3.9252113762678738,0.6140474798967261,-1.5084462869402975,0.1381407880090384,3.331246824431182,-0.5882016919888322,-2.0208317071809168,-1.0296499097675644,3.4548889330923247,3.4949470504727493,2.7546395885257056,3.361652114445284,-2.1767976803894644, 

-3.300142323571273,-2.18152210972249,-1.4849870710875965,-2.6018729891495074,0.8567532957796837,-0.6913086799907093,2.530812094617713,-2.5189568138477547,1.6150122380504834,-2.077155001206889,0.5937527107268776,-1.208099222233689,-3.5442848041373383,-2.169490632316993,1.3128204428383476,-0.021999253115749795,0.15212787258943017,-2.60223879912862,0.565726812370051,3.97402740166568,2.5346808703329753,0.7549809906478222,3.8079125466472394,3.21250067735457,0.7648634688211642,-3.740589397484343,-3.251383233460154,-3.477026279662189,-0.38613481046819764,-0.996521334657138,3.8028002741622924,-2.6561336544030807,3.7823007354612415,2.1397989509041047,2.5939027169959825,1.0609265342239782,1.3498621616538564,-0.18494133183045314,-3.894909144615422,-1.1759513156654018,-0.06342558805153242,1.8407296887208346,-0.25097325803112636,-0.34076067128454657,-2.8986980724351747,-3.912890129572168,2.0662260838159696,-1.440377295378573,3.8750676015480856,-2.238126190726752,-1.2903357961465627,0.19116908532905352,2.039131656484262,-0.2891377287976349,-3.0014196551065897,-1.499988972063604,0.036153357607957126,1.3907920641349412,2.1611996504967372,-2.957313752365166,-3.816678949420946,0.15265857769591573,2.4799096852993303,-3.8991698637609895,1.3797587572298715,1.4944658132559345,-0.40602597130689944,3.318309493935474,1.1548886780559435,-3.958081298788273,-0.12457243588499534,2.8745424487808,2.6431965602987155,1.1932335768998232,1.3895873911890533,0.6279966383136042,-1.8070417986651828,0.4842399242884703,1.3738382785393624,-1.1805629582687294,2.846626938031422,-2.4397001119303416,1.9785664826553857,-1.6831780305049806,2.190394297953456,-0.5781013653113902,2.4615872728976758,-1.1717210986560769,-2.290454098963351,2.1382760673741323,-1.530864418954791,1.86596054181142,1.9557852246218568,-2.2288263927343914,-2.2871029054348124,-2.4084166125834665,-2.8598532978732427,-0.9833392063413271,-3.786976922467028,-3.112637047726075,

1.3965121901072841,2.39821229517909,-3.355763782972913,-2.1463815161136637,-2.338994705569485,3.338668504653045,1.6905161450918937,0.4310768884113143,-1.563856096635038,2.678832381054388,-0.5175523389638403,3.3876497209502014,1.6484144346874654,-0.17574953627773304,-2.9903191700051304,3.808348403741981,-2.721330797247253,-2.3791829982426993,-0.5505459587170325,-0.766384753798822,-2.825988153885647,1.834551354888987,-2.4900394649825124,1.1511651544933024,2.0344476046103894,-2.314140863333434,0.8076339848611198,1.9914270019666915,1.1057496849626673,0.7770184235731925,-1.6361417147560235,1.8528517699320703,3.562467519999598,-0.5955088779076245,2.2574545346512425,-3.5508716827046776,2.6821728199197272,-2.4619998654228183,-0.8392250488802144,-1.5993516325971484,-3.3591708495516057,3.237048023489943,-1.038766579570094,0.24557950780911586,-0.04706987282939945,-2.9427108644564948,-2.348367528884536,-3.3904895277414306,0.06337359956229971,-1.907603585336103,-1.1435071289376646,-3.1354773704221053,2.3004147172200575,-3.147328985689591,3.8856705897055024,-2.5827106844926613,0.5792408994771945,-3.641237323287295,2.296930317246673,-2.4831524174536277,0.22323182726501312,1.9206203452725727,-2.8005481206619525,0.40869739349577383,-2.267062333369765,2.0735683945371575,1.7833215484497096,-2.587607725783336,2.8957324613365873,-3.841799203869246,2.8818959793849217,0.47123048928750677,-0.7742362231532063,2.0699754481786927,1.735432013539759,3.8986093984674124,-1.7753196110961378,-3.9696506207252593,3.4712208665191024,2.8631768363031505,1.8308070201540474,0.13351026337230731,1.655649961990088,2.244236455013942,-1.000992451705125,2.1625802026396608,2.004994553401403,0.9056896923540778,-0.785072608257301,1.5784641541147275,-3.975097137398463,2.1991731737967823,3.1713328196547756,-2.085474340499963,-3.033862525526162,-2.237728097650179,-1.5832261496792137,3.0642280685106735,0.3453314419047562,-1.7063068031485553,

-2.893162481656428,-1.6788442951636666,0.9109687179300208,-1.406891760820427,-0.34111854647201234,-0.44706314386708446,2.6250828858520965,-0.589214766110155,-1.2344094305959814,1.3997728384728418,-2.22814355413177,-0.26203340858756974,-1.4818745014078685,1.0148448173026772,3.018883797558501,-0.4184879988349719,2.275659350335385,-0.34427439550759686,1.249834653737051,-2.945272199779983,-0.5361479442588148,3.2744959092394934,0.8438320082474773,2.134196697896817,0.037604864767154744,-0.015555001375940236,2.7431987215427993,-3.45754452527237,0.586178172397477,3.5421006034635942,0.14288038537857517,-2.444273523776924,2.7835151395478093,-1.9868868611531774,1.6058082918603036,0.32208752317519895,3.590690306241757,0.9946936192214073,2.7038236963818347,-3.936536990443815,3.914720449333104,-3.378283437340908,-1.4229638910818432,3.5692191636541226,-3.9284871810300395,2.5818400433754842,2.889693106934355,-0.48135348633141994,-1.9540384495525505,2.421516157066389,-0.17710396454223076,-2.925291130754431,3.422791942600086,3.1677597360531875,-0.06763879986451737,2.8536199721423374,-0.6513757938872109,1.467719201330409,-0.8160748847366204,0.04593613960648302,-2.4835863773285816,3.719911392887311,-1.6462744940459624,-3.1723235510687893,-2.8454767981676152,-3.8872616464604564,1.727565595699156,0.5159865619269928,2.3566268094780174,0.0566393862730914,2.3345683160332307,1.5661137141747155,2.222787814873403,-0.7481370481833096,1.1821650654998495,-2.561645618456205,-1.4254402928967682,-2.61916303904166,-0.7309021998939009,-2.0686500162752095,-0.7446240469651366,3.8017787394984968,-1.4374453934237499,3.8599275597991625,1.0904490068478685,-0.9992718528487119,2.8598759926687727,0.9566939149485902,-1.9837353589532851,2.342845423815101,-0.5364919301266955,-1.1399106613564687,-1.3577845077993524,1.5789510049051154,-1.8507990087501875,2.466224109643041,-1.6376896448012177,0.35297106868285777,-0.09662806555838088,2.842851300762958,

3.107091475163087,-2.524924461057866,0.6827876715060084,3.185640368137097,-0.4310622477245625,3.374946443870523,-1.7680728763442328,0.8706493935503659,1.4596296781345233,-2.174354133196127,-3.8898598995382656,-0.6662083010344313,3.5078551348538722,-1.2557751213567476,2.2379543638607995,-2.6021094973807406,-1.2643773095803805,-2.843218233295226,1.734166513171008,1.5944609895745137,1.5079785435913502,-1.9728317241096027,1.538880972987271,-2.1816196726724035,-0.6028070725492825,-1.0246230266585021,-1.1575367070390223,-3.538761542069949,1.0531730149275171,1.658532821453596,0.9087095560226848,1.1865020493049965,-2.640474286261938,-2.8044256084891,0.11340034820706268,3.0026618108363126,-2.5283724676222237,-0.2972870503339209,-0.5685413277607765,-0.02168651264386945,-2.7079138361119046,-1.2604748709215157,-1.9049567671718384,2.7562155458358317,2.4026579662112137,-0.5868867338548514,0.8561236863123112,-2.8362751178702403,0.07690635374046906,-1.6244233137047637,2.8772076285536086,1.3727870472511192,1.0677921009793678,-3.001989599446566,-0.23529696400891442,3.892582236695052,3.5863933925813205,1.1606851220835486,-2.786201031744211,1.11301478975924,0.5252969003514201,-0.2506732987099838,-0.5757002442538388,0.7941580452642407,2.7997591081277236,2.008968322975499,0.6348843223778644,3.3976334522882246,-3.482080132467609,3.9307720698544726,-3.5760436586560838,-2.404035630891509,-0.6179787068435125,-3.1399289905186585,0.9893632879816145,-3.6160594876090615,-1.723008951944463,-3.5117065510426313,1.628154648840649,1.347649340715856,-0.9713552539951822,-2.4944459197614304,1.976038632239561,-1.276965673876262,2.3624093392451426,-0.09679248656303763,0.20535555480783518,-3.7720732040674623,1.1538561590322542,-1.1947479805426608,-2.1663597816634743,-0.5289329903063953,-0.9402603418326594,-0.24168767930911805,3.835866833438451,-1.0849754370541564,2.195281066688316,0.42214077239913994,3.1130487128598627,-1.1603771908034242,

-2.0358505585079403,3.2881539172557464,-3.651725889937877,3.606027424488018,0.4512553253674021,-0.9890942665033,3.960418578712889,-3.533098830818947,0.13365087814089716,-3.751223396355617,0.5694059134898675,-2.5562519280390754,1.0476736027162437,3.847389406004652,2.9992204096990474,-0.3853100046330349,1.6676869604137377,2.219750000025514,-0.041255326539491044,0.228267921420521,-2.7937248130224592,-1.0448005951047499,-2.8622299754177067,1.815150026756501,-0.18389604478189447,-0.4089693063458757,3.0879837693228103,0.2209501784924912,-0.7272733446651207,-1.8488638222988332,-3.4239037186418404,-0.6549109301974738,-3.793972140747333,-1.6707684755805756,0.028076078787171888,3.7274645201577785,-3.1249366864513233,1.3843284337329758,-0.0005410312064002554,2.216785834206264,-2.851144017006326,-3.3343789085129956,-0.8062511571803697,2.375698015839201,-2.4665940887208793,2.142217537178192,-1.6776160235050543,-2.2648680991056374,-3.8662752873839485,-0.8107275206209703,-0.9513480696523811,1.2747594895629177,-3.4326527962369022,-2.779168103661825,-3.867392936792527,-3.0896291484207454,1.2143142080807232,-0.7787451826006464,-1.431789486661473,0.46329595395017975,3.9476837047987994,2.675892112144237,1.596985459196671,3.3460687130564635,-3.6821703465353215,-3.437332467075798,-0.20794968009556314,-1.2066606963433815,3.4980164970275913,-0.08348031083865148,0.31719288074680474,3.1620829258497665,-0.4269196334104759,3.0162751141628155,-1.971346005026973,-1.8095223667351314,-1.373108879299279,0.3805141638476277,-2.2389706077841502,1.3714333686501865,-2.8576537375759967,-3.2471978040028846,2.961533969643021,-2.105050371544012,-0.9119679118192359,0.5723367418026584,0.20641575961175995,-3.391808964463145,2.9930074847842265,3.6090849473495368,2.500058433397374,-1.7295853204250058,0.22277436894367586,-1.2846662078591242,0.4373384863013339,3.7952277513040205,-1.5063766582481488,1.3503728473829577,-1.392262341528113,2.195818128120637};
