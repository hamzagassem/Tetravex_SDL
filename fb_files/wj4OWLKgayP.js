/*!CK:4034239177!*//*1427810194,*/

if (self.CavalryLogger) { CavalryLogger.start_js(["l1Ljj"]); }

__d("AbstractTextArea.react",["AbstractTextFieldMixin.react","React","cx"],function(a,b,c,d,e,f,g,h,i){b.__markCompiled&&b.__markCompiled();var j=h.createClass({displayName:"AbstractTextArea",mixins:[g],renderTextField:function(){return this.setTextFieldPropsOn(h.createElement("textarea",{className:"_58an",tabIndex:this.props.tabIndex,onClick:this.props.onClick,onKeyUp:this.props.onKeyUp,rows:this.props.rows}));}});e.exports=j;},null);
__d("XUIDialogCloseButton.react",["React","XUIDialogButton.react","fbt"],function(a,b,c,d,e,f,g,h,i){b.__markCompiled&&b.__markCompiled();var j=g.createClass({displayName:"XUIDialogCloseButton",render:function(){return (g.createElement(h,g.__spread({},this.props,{action:"cancel",label:i._("Fermer")})));}});e.exports=j;},null);
__d("LegacyNAX2ClickHandlers",["AsyncRequest","CSS","DOM","Form","$","ge"],function(a,b,c,d,e,f,g,h,i,j,k,l){b.__markCompiled&&b.__markCompiled();var m={importImageSubmit:function(n){if(l('nax_step_msg'))h.hide('nax_step_msg');var o=l("nax_form_import_image"),p=null,q=null;if(o){p=j.getRadioValue(o.url)||o.url.value;q=k("nax_form_scrape").url.value;}new g().setURI(n).setData({url:p,website:q}).send();},addWebsiteRow:function(){var n=i.scry(document,'div.nax_website_row');if(!n)return;var o=n[n.length-1],p=o.cloneNode(true);h.show(i.find(o,'a.link_remove_row'));h.hide(i.find(o,'a.link_add_row'));i.find(p,'input').value='';i.insertAfter(n[n.length-1],p);}};e.exports=m;},null);
__d("legacy:LegacyNAX2ClickHandlers",["LegacyNAX2ClickHandlers"],function(a,b,c,d,e,f,g){b.__markCompiled&&b.__markCompiled();a.LegacyNAX2ClickHandlers=g;},3);
__d("NAX2ImageImporter",["Arbiter","Button","CSS","DOM","Run","$","copyProperties","ge"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n){b.__markCompiled&&b.__markCompiled();function o(p,q,r,s){this.form=q;this.confirmButton=r;this.profilePic=s;this._arbiterTokens=[g.subscribe(p.CLEAR_SELECTION,this.clearSelection.bind(this)),g.subscribe(p.UPLOAD_SUCCESS,this.onUploadSuccess.bind(this))];k.onLeave(this.destroy.bind(this));var t=l(this.form).url,u;for(u=0;u<t.length;u++)if(t[u].type=="radio")t[u].onchange=this.toggleSelected.bind(this);var v=j.scry(l(this.form),'label');for(u=0;u<v.length;u++){var w=v[u],x=this;w.onclick=function(){var y=n(this.htmlFor);if(y){y.click();x.toggleSelected();}};}this.toggleSelected();}m(o.prototype,{destroy:function(){this._arbiterTokens.forEach(function(p){p.unsubscribe();});this._arbiterTokens=[];},onUploadSuccess:function(p,q){var r=j.find(l(this.profilePic),"img");this._profileImgSrc=r.src;},clearSelection:function(p,q){var r=l(this.form).url;if(r.checked){r.checked=false;}else for(var s=0;s<r.length;s++)if(r[s].checked)r[s].checked=false;this.toggleSelected();},toggleSelected:function(){var p=l(this.form).url;if(p.checked)p=new Array(p);var q=true;for(var r=0;r<p.length;r++)if(p[r].checked){this.replaceLogo(p[r]);q=false;i.addClass(j.find(p[r].parentNode,"div.nax_profile_pic"),'selected');i.addClass(j.find(p[r].parentNode,"div.profilePic"),'selected');}else{i.removeClass(j.find(p[r].parentNode,"div.nax_profile_pic"),'selected');i.removeClass(j.find(p[r].parentNode,"div.profilePic"),'selected');}if(q){h.setEnabled(l(this.confirmButton),false);this.revertLogo();}else h.setEnabled(l(this.confirmButton),true);},replaceLogo:function(){return false;},revertLogo:function(){return false;}});e.exports=o;},null);
__d("NAX2CalloutImageImporter",["ContextualBlindSingleton","DOM","NAX2ImageImporter","Tour","$"],function(a,b,c,d,e,f,g,h,i,j,k){b.__markCompiled&&b.__markCompiled();for(var l in i)if(i.hasOwnProperty(l))n[l]=i[l];var m=i===null?null:i.prototype;n.prototype=Object.create(m);n.prototype.constructor=n;n.__superConstructor__=i;function n(o,p,q,r,s){"use strict";this._isTimeline=s;i.call(this,o,p,q,r);}n.prototype.replaceLogo=function(o){"use strict";var p=h.find(o.parentNode,"img");this.replaceLogoSRC(p.src);};n.prototype.clearSelection=function(o,p){"use strict";if(p&&p.skipping)this._skipping=p.skipping;m.clearSelection.call(this,o,p);};n.prototype.replaceLogoSRC=function(o){"use strict";var p;if(this._isTimeline){p=h.find(k(this.profilePic),".profilePicThumb img");}else p=h.find(k(this.profilePic),"img");this._profileImgSrc=this._profileImgSrc||p.src;p.src=o;if(!this._skipping&&j.getInstance().tourMode&&!this._isTimeline){p.onload=p.onerror=function(){g.show(p,0,0,0,0,true);window.setTimeout(function(){g.show(p,0,0,0,0,true);},5);};}else p.onload=p.onerror=null;};n.prototype.revertLogo=function(){"use strict";this.replaceLogoSRC(this._profileImgSrc);};e.exports=n;},null);
__d("NAX2WizardImageImporter",["CSS","DOM","NAX2ImageImporter","$"],function(a,b,c,d,e,f,g,h,i,j){b.__markCompiled&&b.__markCompiled();for(var k in i)if(i.hasOwnProperty(k))m[k]=i[k];var l=i===null?null:i.prototype;m.prototype=Object.create(l);m.prototype.constructor=m;m.__superConstructor__=i;function m(n,o,p,q,r){"use strict";this.profilePicPreview=r;i.call(this,n,o,p,q);}m.prototype.replaceLogo=function(n){"use strict";var o=h.find(n.parentNode,"div.profilePic"),p=o.cloneNode(true);g.removeClass(p,'small');g.removeClass(p,'selected');h.setContent(h.find(j(this.profilePicPreview),".profilePicThumb"),p);this.showElem(this.profilePicPreview);};m.prototype.showElem=function(n){"use strict";var o=j(n).parentNode;for(var p=0;p<o.children.length;p++)g.hide(o.children[p]);g.show(n);};m.prototype.revertLogo=function(){"use strict";this.showElem(this.profilePic);};e.exports=m;},null);
__d("NAX2LogoStep",["Arbiter","ContextualBlindSingleton","CSS","DOM","HTML","NAX2CalloutImageImporter","NAX2WizardImageImporter","Run","Tour","$","copyProperties","ge"],function(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r){b.__markCompiled&&b.__markCompiled();function s(t,u,v,w){this.arbiter_events=t;this.elements=v;this.type=u;this._hasPhoto=w||false;this._arbiterTokens=[g.subscribe(t.SCRAPE_FINISH,this.onScrapeFinish.bind(this)),g.subscribe(t.STEP_BACK,this.stepBack.bind(this)),g.subscribe(t.SHOW_STEP,this.showStep.bind(this)),g.subscribe(t.UPLOAD_SUCCESS,this.onUploadSuccess.bind(this))];n.onLeave(this.destroy.bind(this));}q(s.prototype,{_showButtons:function(t){for(var u in t)i.conditionShow(u,t[u]);},_showStep:function(t){if(t!=this.elements.scrape_results_container&&i.shown(this.elements.scrape_results_container))g.inform(this.arbiter_events.CLEAR_SELECTION);if(this.type=='wizard')i.conditionShow(this.elements.back_link,t!=this.elements.image_uploader);var u={};if(t==this.elements.image_uploader&&this._hasPhoto){u[this.elements.next_button]=true;u[this.elements.confirm_button]=false;if(this.elements.skip_button)u[this.elements.skip_button]=false;}else{u[this.elements.next_button]=false;u[this.elements.confirm_button]=true;if(this.elements.skip_button)u[this.elements.skip_button]=true;}this._showButtons(u);this._showElem(t);},_showElem:function(t){var u=p(t).parentNode;for(var v=0;v<u.children.length;v++)i.hide(u.children[v]);i.show(t);},destroy:function(){this._arbiterTokens.forEach(function(t){t.unsubscribe();});this._arbiterTokens=[];},onUploadSuccess:function(t,u){this._hasPhoto=true;this._showStep(this.elements.image_uploader);if((this.type=='callout'||this.type=='callout_timeline')&&o.getInstance().tourMode){var v=j.find(p(this.elements.profile_pic),"img");v.onload=v.onerror=function(){h.show(v,0,0,0,0,true);window.setTimeout(function(){h.show(v,0,0,0,0,true);},5);};}},stepBack:function(t,u){if(this.type=='wizard'&&this.elements.step_msg&&r(this.elements.step_msg))i.hide(this.elements.step_msg);if(i.shown(this.elements.scrape_results_container)){this._showStep(this.elements.image_importer);}else if(i.shown(this.elements.image_importer)){this._showStep(this.elements.image_uploader);}else if(i.shown(this.elements.scrape_indicator))this._showStep(this.elements.image_importer);},showStep:function(t,u){this._showStep(u.stepName);},onScrapeFinish:function(t,u){j.setContent(p(this.elements.scrape_results),k(u.images));this._showElem(this.elements.scrape_results_container);if(u.image_count){var v;switch(this.type){case 'wizard':v=new m({CLEAR_SELECTION:this.arbiter_events.CLEAR_SELECTION,UPLOAD_SUCCESS:this.arbiter_events.UPLOAD_SUCCESS},this.elements.form_scrape_results,this.elements.confirm_button,this.elements.profile_pic,this.elements.profile_pic_preview);break;case 'callout':v=new l({CLEAR_SELECTION:this.arbiter_events.CLEAR_SELECTION,UPLOAD_SUCCESS:this.arbiter_events.UPLOAD_SUCCESS},this.elements.form_scrape_results,this.elements.confirm_button,this.elements.profile_pic,false);break;case 'callout_timeline':v=new l({CLEAR_SELECTION:this.arbiter_events.CLEAR_SELECTION,UPLOAD_SUCCESS:this.arbiter_events.UPLOAD_SUCCESS},this.elements.form_scrape_results,this.elements.confirm_button,this.elements.profile_pic,true);break;default:throw "Invalid type: "+this.type;}}}});e.exports=s;},null);
__d("NAX2TextAreaWithCounter.react",["AbstractTextArea.react","Button","DOM","React","cx"],function(a,b,c,d,e,f,g,h,i,j,k){b.__markCompiled&&b.__markCompiled();var l=j,m=l.PropTypes,n=j.createClass({displayName:"NAX2TextAreaWithCounter",propTypes:{maxLength:m.number.isRequired,rows:m.number,name:m.string,placeholder:m.string,value:m.string,saveButtonID:m.string},getInitialState:function(){return {counter:this.props.maxLength-this.props.value.length,displayValue:this.props.value,actionButton:this.props.saveButtonID?i.find(document.body,'#'+this.props.saveButtonID):null};},renderCounter:function(){return (j.createElement("div",{className:"_3v26"},this.state.counter));},render:function(){var o=this.renderCounter();if(this.state.actionButton)h.setEnabled(this.state.actionButton,this.state.displayValue.length);var p=j.createElement(g,j.__spread({},this.props,{onChange:this._onChange,value:this.state.displayValue}));return (j.createElement("div",{className:"_3v27"},o,p));},_onChange:function(event){this.setState({displayValue:event.target.value,counter:this.props.maxLength-event.target.value.length});}});e.exports=n;},null);
__d("NAX2URLTextInput",["DOMEventListener"],function(a,b,c,d,e,f,g){b.__markCompiled&&b.__markCompiled();var h={addEvent:function(i){var j=i.placeholder;g.add(i,"focus",function(){i.value=i.value||"http://";i.dir="ltr";i.placeholder="";i.setSelectionRange(i.value.length,i.value.length);});g.add(i,"blur",function(){if(i.value==="http://"||i.value===""){i.value="";i.dir="";}i.placeholder=j;});}};e.exports=h;},null);
__d("legacy:nax2-wizard-js",["NAX2LogoStep"],function(a,b,c,d){b.__markCompiled&&b.__markCompiled();a.NAX2LogoStep=b('NAX2LogoStep');},3);
__d("TimelineFileInput",["Event","Rect","Style","Vector","$"],function(a,b,c,d,e,f,g,h,i,j,k){b.__markCompiled&&b.__markCompiled();function l(m,n,o){"use strict";this.container=k(m);this.input=n;this.form=o;g.listen(this.input,'click',function(event){event.stop();});g.listen(this.input,'change',this._onValueChange.bind(this));g.listen(this.container,'mousemove',this._onMouseMove.bind(this));}l.prototype._onValueChange=function(event){"use strict";if(this.input.value){this.form.onsubmit(event);this.form.submit();this.input.value=null;}};l.prototype._onMouseMove=function(event){"use strict";if(!this.inputDimensions)this.inputDimensions=j.getElementDimensions(this.input);this.containerPosition=j.getElementPosition(this.container);this.containerRect=h.newFromVectors(this.containerPosition,j.getElementDimensions(this.container));var m=j.getEventPosition(event),n=0,o=0;if(this.containerRect.contains(m)){n=(m.x-this.containerPosition.x+20-this.inputDimensions.x)+'px';o=(m.y-this.containerPosition.y-10)+'px';}i.set(this.input,'top',o);i.set(this.input,'left',n);};e.exports=l;},null);
__d("legacy:TimelineFileInput",["TimelineFileInput"],function(a,b,c,d){b.__markCompiled&&b.__markCompiled();a.TimelineFileInput=b('TimelineFileInput');},3);