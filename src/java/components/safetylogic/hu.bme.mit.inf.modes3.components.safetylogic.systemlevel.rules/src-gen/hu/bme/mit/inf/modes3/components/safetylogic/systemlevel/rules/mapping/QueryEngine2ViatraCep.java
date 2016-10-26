package hu.bme.mit.inf.modes3.components.safetylogic.systemlevel.rules.mapping;

import hu.bme.mit.inf.modes3.components.safetylogic.systemlevel.rules.events.queryresult.DivergentTurnoutEvent_Event;
import hu.bme.mit.inf.modes3.components.safetylogic.systemlevel.rules.events.queryresult.TrainLeftStation_Event;
import hu.bme.mit.inf.modes3.components.safetylogic.systemlevel.rules.events.queryresult.TrainOnStation_Event;
import hu.bme.mit.inf.safetylogic.rulepatterns.DivergentTurnoutMatch;
import hu.bme.mit.inf.safetylogic.rulepatterns.DivergentTurnoutMatcher;
import hu.bme.mit.inf.safetylogic.rulepatterns.TrainOnStationMatch;
import hu.bme.mit.inf.safetylogic.rulepatterns.TrainOnStationMatcher;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.viatra.cep.core.streams.EventStream;
import org.eclipse.viatra.query.runtime.api.IMatchProcessor;
import org.eclipse.viatra.query.runtime.emf.EMFScope;
import org.eclipse.viatra.query.runtime.exception.ViatraQueryException;
import org.eclipse.viatra.transformation.evm.specific.Lifecycles;
import org.eclipse.viatra.transformation.evm.specific.crud.CRUDActivationStateEnum;
import org.eclipse.viatra.transformation.runtime.emf.rules.EventDrivenTransformationRuleGroup;
import org.eclipse.viatra.transformation.runtime.emf.rules.eventdriven.EventDrivenTransformationRule;
import org.eclipse.viatra.transformation.runtime.emf.rules.eventdriven.EventDrivenTransformationRuleFactory;
import org.eclipse.viatra.transformation.runtime.emf.transformation.eventdriven.EventDrivenTransformation;
import org.eclipse.viatra.transformation.runtime.emf.transformation.eventdriven.InconsistentEventSemanticsException;

@SuppressWarnings("all")
public class QueryEngine2ViatraCep {
  private EventStream eventStream;
  
  private ResourceSet resourceSet;
  
  private EventDrivenTransformation transformation;
  
  private QueryEngine2ViatraCep(final ResourceSet resourceSet, final EventStream eventStream) {
    this.resourceSet = resourceSet;
    this.eventStream = eventStream;
    registerRules();
  }
  
  public static QueryEngine2ViatraCep register(final ResourceSet resourceSet, final EventStream eventStream) {
    return new QueryEngine2ViatraCep(resourceSet, eventStream);
  }
  
  public EventDrivenTransformationRuleGroup getRules() {
    EventDrivenTransformationRuleGroup ruleGroup = new EventDrivenTransformationRuleGroup(
    	createtrainOnStation_MappingRule(), 
    	createdivergentTurnout_MappingRule()
    );
    return ruleGroup;
  }
  
  private void registerRules() {
    try {
    	transformation = EventDrivenTransformation.forScope(new EMFScope(resourceSet)).addRules(getRules()).build();
    } catch (ViatraQueryException e) {
    	e.printStackTrace();
    }
  }
  
  public EventDrivenTransformationRule<TrainOnStationMatch, TrainOnStationMatcher> createtrainOnStation_MappingRule() {
    try{
      EventDrivenTransformationRuleFactory.EventDrivenTransformationRuleBuilder<TrainOnStationMatch, TrainOnStationMatcher> builder = new EventDrivenTransformationRuleFactory().createRule();
      builder.addLifeCycle(Lifecycles.getDefault(false, true));
      builder.precondition(TrainOnStationMatcher.querySpecification());
      
      IMatchProcessor<TrainOnStationMatch> actionOnAppear_0 = new IMatchProcessor<TrainOnStationMatch>() {
        public void process(final TrainOnStationMatch matchedPattern) {
          TrainOnStation_Event event = new TrainOnStation_Event(null);
          event.setQueryMatch(matchedPattern);
          eventStream.push(event);
        }
      };
      builder.action(CRUDActivationStateEnum.CREATED, actionOnAppear_0);
      
      IMatchProcessor<TrainOnStationMatch> actionOnDisappear_0 = new IMatchProcessor<TrainOnStationMatch>() {
        public void process(final TrainOnStationMatch matchedPattern) {
          TrainLeftStation_Event event = new TrainLeftStation_Event(null);
          event.setQueryMatch(matchedPattern);
          eventStream.push(event);
        }
      };
      builder.action(CRUDActivationStateEnum.DELETED, actionOnDisappear_0);
      
      return builder.build();
    } catch (ViatraQueryException e) {
      e.printStackTrace();
    } catch (InconsistentEventSemanticsException e) {
      e.printStackTrace();
    }
    return null;
  }
  
  public EventDrivenTransformationRule<DivergentTurnoutMatch, DivergentTurnoutMatcher> createdivergentTurnout_MappingRule() {
    try{
      EventDrivenTransformationRuleFactory.EventDrivenTransformationRuleBuilder<DivergentTurnoutMatch, DivergentTurnoutMatcher> builder = new EventDrivenTransformationRuleFactory().createRule();
      builder.addLifeCycle(Lifecycles.getDefault(false, true));
      builder.precondition(DivergentTurnoutMatcher.querySpecification());
      
      IMatchProcessor<DivergentTurnoutMatch> actionOnAppear_0 = new IMatchProcessor<DivergentTurnoutMatch>() {
        public void process(final DivergentTurnoutMatch matchedPattern) {
          DivergentTurnoutEvent_Event event = new DivergentTurnoutEvent_Event(null);
          event.setQueryMatch(matchedPattern);
          eventStream.push(event);
        }
      };
      builder.action(CRUDActivationStateEnum.CREATED, actionOnAppear_0);
      
      IMatchProcessor<DivergentTurnoutMatch> actionOnDisappear_0 = new IMatchProcessor<DivergentTurnoutMatch>() {
        public void process(final DivergentTurnoutMatch matchedPattern) {
        }
      };
      builder.action(CRUDActivationStateEnum.DELETED, actionOnDisappear_0);
      
      return builder.build();
    } catch (ViatraQueryException e) {
      e.printStackTrace();
    } catch (InconsistentEventSemanticsException e) {
      e.printStackTrace();
    }
    return null;
  }
  
  public void dispose() {
    this.transformation = null;
  }
}
